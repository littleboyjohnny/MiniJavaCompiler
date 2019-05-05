// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "IRTBuilder.h"
#include "IRTIncludes.h"

#include <cassert>
#include <ASTIncludes.h>

const CCodeFragment* IRTree::CIRTBuilder::BuildAST( const CGoal * goal,
                                                    const CSymbolTable* st,
                                                    const CFramesHolder* fh ) {
    framesHolder = fh;
    symbolTable = st;
    goal->Accept( this );
    return head;
}

void IRTree::CIRTBuilder::Visit( const CGoal* acceptable ) {
    assert( acceptable != nullptr );
    assert( acceptable->mainClass != nullptr );

    acceptable->mainClass->Accept( this );

    if ( acceptable->classDeclarationS )
        acceptable->classDeclarationS->Accept( this );
}

void IRTree::CIRTBuilder::Visit( const CMainClass* acceptable ) {
    currClass = symbolTable->TryResolveClass( CSymbol::GetIntern( acceptable->className->identifier ) );
    currMethod = currClass->GetScope()->TryResolveMethod( CSymbol::GetIntern( "main" ) );
    currFrame = framesHolder->GetFrame( currClass->GetName()->GetString(), currMethod->GetName()->GetString() );

    const IStm* body = nullptr;
    if ( acceptable->statementS ) {
        acceptable->statementS->Accept(this);
        body = currWrapper->ToStm();
    }

    CCodeFragment* fragment = new CCodeFragment( currFrame, body, head );
    head = fragment;

    currWrapper = nullptr;
    currFrame = nullptr;
    currMethod = nullptr;
    currClass = nullptr;
}

void IRTree::CIRTBuilder::Visit( const CClassDeclarationList* acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++) {
        acceptable->children[i]->Accept( this );
    }
}

void IRTree::CIRTBuilder::Visit( const CClassDeclaration* acceptable ) {
    currClass = symbolTable->TryResolveClass( CSymbol::GetIntern( acceptable->className->identifier ) );

    if ( acceptable->methodDeclarationS )
        acceptable->methodDeclarationS->Accept( this );

    currClass = nullptr;
}

void IRTree::CIRTBuilder::Visit( const CMethodDeclarationList* acceptable ) {
    for ( int i = 0; i < acceptable->children.size(); i++ ) {
        acceptable->children[i]->Accept( this );
    }
}

void IRTree::CIRTBuilder::Visit( const CMethodDeclaration* acceptable ) {
    currMethod = currClass->GetScope()->TryResolveMethod( CSymbol::GetIntern( acceptable->methodIdentifier->identifier ) );
    currFrame = framesHolder->GetFrame( currClass->GetName()->GetString(), currMethod->GetName()->GetString());

    const IStm* body = nullptr;
    if ( acceptable->statementS ) {
        acceptable->statementS->Accept(this);
        body = currWrapper->ToStm();
    }
    acceptable->returnExpression->Accept( this );
    body = new CSeqStm(
                body,
                currWrapper->ToStm()
            );

    CCodeFragment* fragment = new CCodeFragment( currFrame, body, head );
    head = fragment;

    currWrapper = nullptr;
    currFrame = nullptr;
    currMethod = nullptr;
}

void IRTree::CIRTBuilder::Visit( const CArrayAssignmentStatement* acceptable ) {
    assert( acceptable->expression != nullptr );
    assert( acceptable->indexExpression != nullptr );
    assert( acceptable->arrayName != nullptr );

    acceptable->arrayName->Accept( this );
    const IExp* base = currWrapper->ToExp();

    acceptable->indexExpression->Accept( this );
    const IExp* index = currWrapper->ToExp();

    acceptable->expression->Accept( this );
    const IExp* value = currWrapper->ToExp();

    currWrapper = new CStmConverterer(
                    new CMoveStm(
                            new CMemExp(
                                    new CBinOpExp(
                                            CBinOpExp::EBinOp::PLUS,
                                            base,
                                            new CBinOpExp(
                                                    CBinOpExp::EBinOp::MULTIPLY,
                                                    new CBinOpExp(
                                                            CBinOpExp::EBinOp::PLUS,
                                                            index,
                                                            new CConstExp(1)
                                                    ),
                                                    new CConstExp( currFrame->WordSize() )
                                            )
                                        )
                                    ),
                            value
                            )
            );

}

void IRTree::CIRTBuilder::Visit( const CCurlyBraceStatement* acceptable ) {
    if ( acceptable->statementS ) {
        acceptable->statementS->Accept(this);
        currWrapper = new CStmConverterer(currWrapper->ToStm());
    } else {
        currWrapper = new CStmConverterer( nullptr );
    }
}

void IRTree::CIRTBuilder::Visit( const CCallExpression* acceptable ) {
    assert( acceptable->expression != nullptr );
    assert( acceptable->identifier != nullptr );

    acceptable->expression->Accept( this );
    const IExp* base = currWrapper->ToExp();

    currList = new CExpList( base );
    if ( acceptable->expressionParamS ) {
        acceptable->expressionParamS->Accept(this);
    }

    currWrapper = new CExpConverter(
                    new CCallExp(
                            new CNameExp(
                                    CLabel( std::string( acceptable->identifier->identifier ) )
                                    ),
                            currList
                            )
            );
    currList = nullptr;
}

void IRTree::CIRTBuilder::Visit( const CExpressionParamList* acceptable ) {
    for ( int i = 0; i < acceptable->children.size(); i++ ) {
        acceptable->children[i]->Accept( this );
        currList->Add( currWrapper->ToExp() );
    }
}

void IRTree::CIRTBuilder::Visit( const CIdentifierExpression* acceptable ) {
    acceptable->identifier->Accept( this );
}

void IRTree::CIRTBuilder::Visit( const CTerminalIdentifier* acceptable ) {
    //INameScope::SymbolType st = symbolTable->ResolveType( CSymbol::GetIntern( acceptable->identifier ) );
    const IExp* exp = nullptr;

    auto varInfo = currClass->GetScope()->TryResolveVariable( CSymbol::GetIntern( acceptable->identifier ) );
    if ( varInfo ) {
        exp = new CMemExp(
                new CBinOpExp(
                        CBinOpExp::EBinOp::PLUS,
                        currFrame->GetAccess("this"),
                        new CBinOpExp(
                                CBinOpExp::EBinOp::MULTIPLY,
                                new CBinOpExp(
                                        CBinOpExp::EBinOp::PLUS,
                                        new CConstExp(varInfo->GetOffset()),
                                        new CConstExp(1)
                                ),
                                new CConstExp(currFrame->WordSize())
                        )
                )
        );
    } else {
        exp = currFrame->GetAccess( acceptable->identifier );
    }

    currWrapper = new CExpConverter( exp );
}

void IRTree::CIRTBuilder::Visit( const CTerminalIntliteral* acceptable ) {
    currWrapper = new CExpConverter(
            new CConstExp( acceptable->intliteral )
    );
}

void IRTree::CIRTBuilder::Visit( const CIfElseStatement* acceptable ) {
    static int counter = 0;

    assert(acceptable->condition != nullptr);
    assert(acceptable->ifStatement != nullptr);
    assert(acceptable->elseStatement != nullptr);

    counter++;
    CLabel t(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___IfMainBody_" + (char)('0' + counter));
    CLabel f(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___IfElseBody_" + (char)('0' + counter));

    CLabel e(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___IfEnd_" + (char)('0' + counter));

    acceptable->condition->Accept( this );
    auto conditional = currWrapper->ToConditional( &t, &f );

    acceptable->ifStatement->Accept( this );
    auto ifStm = currWrapper->ToStm();

    acceptable->elseStatement->Accept( this );
    auto elseStm = currWrapper->ToStm();

    currWrapper = new CStmConverterer(
                    new CSeqStm(
                            conditional,
                            new CSeqStm(
                                    new CLabelStm(t),
                                    new CSeqStm(
                                            ifStm,
                                            new CSeqStm(
                                                new CJumpStm(e),
                                                new CSeqStm(
                                                        new CLabelStm(f),
                                                        new CSeqStm(
                                                                elseStm,
                                                                new CLabelStm(e)
                                                        )
                                                )
                                            )
                                    )
                            )
                    )
            );
}

void IRTree::CIRTBuilder::Visit( const CIntliteralExpression* acceptable ) {
    acceptable->intliteral->Accept( this );
}

void IRTree::CIRTBuilder::Visit( const CLengthExpression* acceptable ) {
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currWrapper->ToExp()
            );
} 

void IRTree::CIRTBuilder::Visit( const CNewArrayExpression* acceptable ) {
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currFrame->ExternalCall(
                            "malloc",
                            new CBinOpExp(
                                    CBinOpExp::EBinOp::MULTIPLY,
                                    new CBinOpExp(
                                            CBinOpExp::EBinOp::PLUS,
                                            currWrapper->ToExp(),
                                            new CConstExp(1)
                                    ),
                                    new CConstExp(currFrame->WordSize())
                            )
                    )
                  );
} 

void IRTree::CIRTBuilder::Visit( const CNewIdentifierExpression* acceptable ) {
    const CClassInfo* loacalClass = symbolTable->TryResolveClass( CSymbol::GetIntern(acceptable->identifier->identifier) );
    int sizeOfClass = loacalClass->GetSize();

    currWrapper = new CExpConverter(
                    currFrame->ExternalCall(
                            "malloc",
                            new CBinOpExp(
                                    CBinOpExp::EBinOp::PLUS,
                                    new CConstExp( sizeOfClass ),
                                    new CConstExp( currFrame->WordSize() )
                                    )
                            )
            );
} 

void IRTree::CIRTBuilder::Visit( const CNotExpression* acceptable ) {
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    new CBinOpExp(CBinOpExp::EBinOp::XOR, new CConstExp(0), currWrapper->ToExp())
            );
} 

void IRTree::CIRTBuilder::Visit( const CParensExpression* acceptable ) {
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currWrapper->ToExp()
            );
} 

void IRTree::CIRTBuilder::Visit( const CPrintlnStatement* acceptable ) {
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currFrame->ExternalCall("println", currWrapper->ToExp())
            );
} 

void IRTree::CIRTBuilder::Visit( const CSquarebracketsExpression* acceptable ) {
    assert( acceptable->expression != nullptr );
    assert( acceptable->squarebraketsExpression != nullptr );

    acceptable->expression->Accept( this );
    const IExp* base = currWrapper->ToExp();

    acceptable->squarebraketsExpression->Accept( this );
    const IExp* index = currWrapper->ToExp();

    currWrapper = new CExpConverter(
                     new CMemExp(
                             new CBinOpExp(
                                     CBinOpExp::EBinOp::PLUS,
                                     base,
                                     new CBinOpExp(
                                             CBinOpExp::EBinOp::MULTIPLY,
                                             new CBinOpExp(
                                                     CBinOpExp::EBinOp::PLUS,
                                                     index,
                                                     new CConstExp(1)
                                                     ),
                                             new CConstExp( currFrame->WordSize() )
                                             )
                                     )
                             )
            );
} 

void IRTree::CIRTBuilder::Visit( const CStatementList* acceptable ) {
    acceptable->children.back()->Accept( this );

    for ( int i = acceptable->children.size() - 2; i >= 0; i-- ) {
        ISubtreeWrapper* prevStm = currWrapper;
        acceptable->children[i]->Accept( this );
        currWrapper = new CStmConverterer(
                        new CSeqStm(currWrapper->ToStm(), prevStm->ToStm())
                );
    }
} 

void IRTree::CIRTBuilder::Visit( const CThisExpression* acceptable ) {
    currWrapper = new CExpConverter(
                    currFrame->GetAccess( "this" )
            );
} 

void IRTree::CIRTBuilder::Visit( const CTrueExpression* acceptable ) {
    currWrapper = new CExpConverter(
                    new CConstExp(1)
            );
} 

void IRTree::CIRTBuilder::Visit( const CFalseExpression* acceptable ) {
    currWrapper = new CExpConverter(
                    new CConstExp(0)
            );
} 

void IRTree::CIRTBuilder::Visit( const CVarAssignmentStatement* acceptable ) {
    acceptable->varName->Accept( this );
    const IExp* lv = currWrapper->ToExp();

    acceptable->expression->Accept( this );
    const IExp* rv = currWrapper->ToExp();

    currWrapper = new CStmConverterer(
                    new CMoveStm(lv, rv)
            );
} 

void IRTree::CIRTBuilder::Visit( const CWhileStatement* acceptable ) {
    static int counter = 0;
    counter++;

    CLabel b(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___ToBegLoop_" + (char)('0' + counter));
    CLabel t(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___ToBodyLoop_" + (char)('0' + counter));
    CLabel f(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___ToEndLoop_" + (char)('0' + counter));

    acceptable->condition->Accept( this );
    auto condition = currWrapper->ToConditional(&t, &f);

    acceptable->statement->Accept( this );
    auto body = currWrapper->ToStm();

    currWrapper = new CStmConverterer(
                    new CSeqStm(
                            new CLabelStm(b),
                            new CSeqStm(
                                    condition,
                                    new CSeqStm(
                                        new CLabelStm(t),
                                        new CSeqStm(
                                            body,
                                            new CSeqStm(
                                                new CJumpStm(b),
                                                new CLabelStm(f)
                                            )
                                        )
                                    )
                            )
                    )
            );
} 

void IRTree::CIRTBuilder::Visit( const CBinaryOpExpression* acceptable ) {

    auto resolveOp = [](CBinaryOpExpression::OpType type) -> CBinOpExp::EBinOp {
        using InType = CBinaryOpExpression::OpType;
        using OutType = CBinOpExp::EBinOp;
        switch (type) {
            case InType::PLUS : return OutType::PLUS;
            case InType::MULTIPLY : return OutType::MULTIPLY ;
            case InType::MINUS : return OutType::MINUS ;
            case InType::AND : return OutType::AND ;
            case InType::LESS : return OutType::LESS ;
        }
    };

    acceptable->left->Accept( this );
    const ISubtreeWrapper* leftExp = currWrapper;

    acceptable->right->Accept( this );
    const ISubtreeWrapper* rightExp = currWrapper;

    if (acceptable->opType == CBinaryOpExpression::OpType::LESS) {
        currWrapper = new CRelativeCmpWrapper( CCJumpStm::ERelOp::LT, leftExp->ToExp(), rightExp->ToExp() );
    } else if ( acceptable->opType == CBinaryOpExpression::OpType::AND ) {
        currWrapper = new CFromAndConverter( leftExp, rightExp );
    } else {
        currWrapper = new CExpConverter(
                        new CBinOpExp(
                                resolveOp(acceptable->opType), leftExp->ToExp(), rightExp->ToExp()
                            )
                );
    }
} 
