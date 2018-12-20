// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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
    //assert(acceptable->statementS != nullptr);
    if ( acceptable->statementS )
        acceptable->statementS->Accept( this );
}

void IRTree::CIRTBuilder::Visit( const CClassDeclarationList* acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++) {
        acceptable->children[i]->Accept( this );
    }
}

void IRTree::CIRTBuilder::Visit( const CClassDeclaration* acceptable ) {
    if ( acceptable->methodDeclarationS )
        acceptable->methodDeclarationS->Accept( this );
}

void IRTree::CIRTBuilder::Visit( const CMethodDeclarationList* acceptable ) {
    for ( int i = 0; i < acceptable->children.size(); i++ ) {
        acceptable->children[i]->Accept( this );
    }
}

void IRTree::CIRTBuilder::Visit( const CMethodDeclaration* acceptable ) {
    
}

void IRTree::CIRTBuilder::Visit( const CParamList* acceptable ) {
    assert(false);
}

void IRTree::CIRTBuilder::Visit( const CParam* acceptable ) {
    assert(false);
}

void IRTree::CIRTBuilder::Visit( const CArrayAssignmentStatement* acceptable ) {

}

void IRTree::CIRTBuilder::Visit( const CCurlyBraceStatement* acceptable ) {

}

void IRTree::CIRTBuilder::Visit( const CCallExpression* acceptable ) {

}

void IRTree::CIRTBuilder::Visit( const CExpressionParamList* acceptable ) {

}

void IRTree::CIRTBuilder::Visit( const CIdentifierExpression* acceptable ) {

}

void IRTree::CIRTBuilder::Visit( const CIfElseStatement* acceptable ) {
    CLabel t("MainBody");
    CLabel f("ElseBody");

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
    //
}

void IRTree::CIRTBuilder::Visit( const CLengthExpression* acceptable ) {
    acceptable->expression->Accept( this );
    currWrapper = new CExpConverter(
                    currWrapper->ToExp()
                    //TODO:
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
                    new CBinOpExp(CBinOpExp::EBinOp::XOR, CConstExp(0), currWrapper->ToExp())
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
    //// with slides, need Frame
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
                    currFrame->GetAddress( CFrame.This() )->ToExp()
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
    CLabel b("ToBegLoop");
    CLabel t("ToBodyLoop");
    CLabel f("ToEndLoop");

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
    acceptable->left->Accept( this );
    auto leftExp = currWrapper->ToExp();

    acceptable->right->Accept( this );
    auto rightExp = currWrapper->ToExp();

    if (acceptable->opType == CBinaryOpExpression::OpType::LESS) {
        currWrapper = new CRelativeCmpWrapper(
                        new CBinOpExp(
                                CBinOpExp::EBinOp::LESS, leftExp, rightExp
                            )
                );
    } else if ( acceptable->opType == CBinaryOpExpression::OpType::AND ) {
        currWrapper = new CFromAndConverter(
                        new CBinOpExp(
                                CBinOpExp::EBinOp::AND, leftExp, rightExp
                            )
                );
    } else {
        currWrapper = new CExpConverter(
                        new CBinOpExp(
                                acceptable->opType, leftExp, rightExp
                            )
                );
    }
} 
