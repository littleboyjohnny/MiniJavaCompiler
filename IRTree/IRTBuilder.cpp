#include "IRTBuilder.h"
#include "IRTIncludes.h"

#include <cassert>
#include <ASTIncludes.h>

void IRTree::CIRTBuilder::Visit( const CGoal* acceptable ) {
    assert( acceptable != nullptr );
    assert( acceptable->mainClass != nullptr );

    acceptable->mainClass->Accept( this );

    if ( acceptable->classDeclarationS )
        acceptable->classDeclarationS->Accept( this );
}

void IRTree::CIRTBuilder::Visit( const CMainClass* acceptable ) {
    currClass = symbolTable->TryResolveClass( new CSymbol( acceptable->className->identifier ) );
    if ( acceptable->statementS )
        acceptable->statementS->Accept( this );

    currClass = nullptr;
}

void IRTree::CIRTBuilder::Visit( const CClassDeclarationList* acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++) {
        acceptable->children[i]->Accept( this );
    }
}

void IRTree::CIRTBuilder::Visit( const CClassDeclaration* acceptable ) {
    currClass = symbolTable->TryResolveClass(new CSymbol( acceptable->className->identifier ) );

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
    currMethod = currClass->GetScope()->TryResolveMethod( new CSymbol( acceptable->methodIdentifier->identifier ) );
    currFrame = framesHolder->GetFrame( new CSymbol( currClass->GetName()->GetString() + "::"
            + currMethod->GetName()->GetString()) );



    acceptable->statementS->Accept( this );
    auto body = currWrapper->ToStm();

    currMethod = nullptr;
}

void IRTree::CIRTBuilder::Visit( const CArrayAssignmentStatement* acceptable ) {
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
    acceptable->statementS->Accept( this );
    currWrapper = new CStmConverterer( currWrapper->ToStm() );
}

void IRTree::CIRTBuilder::Visit( const CCallExpression* acceptable ) {
    acceptable->expression->Accept( this );
    const IExp* base = currWrapper->ToExp();

    acceptable->identifier->Accept( this );
    const IExp* method = currWrapper->ToExp();

    acceptable->expressionParamS->Accept( this );

    currWrapper = new CExpConverter(
                    new CCallExp(
                            new CNameExp(
                                    new CLabel(currClass->GetName()->GetString() + "::" +
                                               std::string(acceptable->identifier->identifier))
                                    ),
                            currList
                            )
            );
    currList = nullptr;
}

void IRTree::CIRTBuilder::Visit( const CExpressionParamList* acceptable ) {
    CExpList* expList = new CExpList();
    for ( int i = 0; i < acceptable->children.size(); i++ ) {
        acceptable->children[i]->Accept( this );
        expList->Add( currWrapper->ToExp() );
    }
    currList = expList;
}

void IRTree::CIRTBuilder::Visit( const CIdentifierExpression* acceptable ) {
    acceptable->identifier->Accept( this );
}

void IRTree::CIRTBuilder::Visit( const CTerminalIdentifier* acceptable ) {
    currWrapper = new CExpConverter( currFrame->GetAccess( acceptable->identifier ) );
}

void IRTree::CIRTBuilder::Visit( const CTerminalIntliteral* acceptable ) {
    currWrapper = new CExpConverter(
            new CConstExp( acceptable->intliteral )
    );
}

void IRTree::CIRTBuilder::Visit( const CIfElseStatement* acceptable ) {
    static int counter = 0;
    counter++;
    CLabel t(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___IfMainBody_" + (char)('0' + counter));
    CLabel f(currClass->GetName()->GetString() + "::" +
             currMethod->GetName()->GetString() + "::" +
             "___IfElseBody_" + (char)('0' + counter));

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
                                                    new CLabelStm(f),
                                                    elseStm
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
    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currWrapper->ToExp()
            );
} 

void IRTree::CIRTBuilder::Visit( const CNewArrayExpression* acceptable ) {
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
                                    new CConstExp(currFrame->WordSize()
                            )
                    )
            )
    );
} 

void IRTree::CIRTBuilder::Visit( const CNewIdentifierExpression* acceptable ) {
    const CClassInfo* currClass = symbolTable->TryResolveClass(new CSymbol(acceptable->identifier->identifier));
    int sizeOfClass = currClass->GetSize();

    currWrapper = new CExpConverter(
                    currFrame->ExternalCall(
                            "malloc",
                            new CBinOpExp(
                                    CBinOpExp::EBinOp::MULTIPLY,
                                    new CConstExp(sizeOfClass),
                                    new CConstExp(currFrame->WordSize())
                                    )
                            )
            );
} 

void IRTree::CIRTBuilder::Visit( const CNotExpression* acceptable ) {
    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    new CBinOpExp(CBinOpExp::EBinOp::XOR, new CConstExp(0), currWrapper->ToExp())
            );
} 

void IRTree::CIRTBuilder::Visit( const CParensExpression* acceptable ) {
    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currWrapper->ToExp()
            );
} 

void IRTree::CIRTBuilder::Visit( const CPrintlnStatement* acceptable ) {
    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currFrame->ExternalCall("println", currWrapper->ToExp())
            );
} 

void IRTree::CIRTBuilder::Visit( const CSquarebracketsExpression* acceptable ) {
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
                    currFrame->GetAccess( currFrame->This()->getName() )
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
    auto leftExp = currWrapper->ToExp();

    acceptable->right->Accept( this );
    auto rightExp = currWrapper->ToExp();

    if (acceptable->opType == CBinaryOpExpression::OpType::LESS) {
        currWrapper = new CRelativeCmpWrapper( CCJumpStm::ERelOp::LT, leftExp, rightExp );
    } else if ( acceptable->opType == CBinaryOpExpression::OpType::AND ) {
        currWrapper = new CFromAndConverter( leftExp, rightExp );
    } else {
        currWrapper = new CExpConverter(
                        new CBinOpExp(
                                resolveOp(acceptable->opType), leftExp, rightExp
                            )
                );
    }
} 
