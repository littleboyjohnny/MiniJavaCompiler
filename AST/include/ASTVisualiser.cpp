#include "ASTVisualiser.h"

#include "AdditionalExpressionParam.hpp"
#include "AdditionalExpressionParamS.hpp"
#include "AdditionalParam.hpp"
#include "AdditionalParamS.hpp"
#include "AndExpression.hpp"
#include "ArrayAssignmentStatement.hpp"
#include "BooleanType.hpp"
#include "CurlyBraceStatement.hpp"
#include "CustomType.hpp"
#include "DotExpression.hpp"
#include "ExpressionParamS.hpp"
#include "FalseExpression.hpp"
#include "Goal.hpp"
#include "IdentifierExpression.hpp"
#include "IfElseStatement.hpp"
#include "IntArrayType.hpp"
#include "IntliteralExpression.hpp"
#include "IntType.hpp"
#include "LengthExpression.hpp"
#include "LessExpression.hpp"
#include "MinusExpression.hpp"
#include "MultiplyExpression.hpp"
#include "NewArrayExpression.hpp"
#include "NewIdentifierExpression.hpp"
#include "NotExpression.hpp"
#include "Params.hpp"
#include "ParensExpression.hpp"
#include "PlusExpression.hpp"
#include "PrintlnStatement.hpp"
#include "SquarebracketsExpression.hpp"
#include "StatementS.hpp"
#include "TerminalIdentifier.hpp"
#include "TerminalIntliteral.hpp"
#include "ThisExpression.hpp"
#include "TrueExpression.hpp"
#include "VarAssignmentStatement.hpp"
#include "WhileStatement.hpp"
#include "ClassDeclaration.hpp"
#include "MainClass.hpp"
#include "ClassDeclarationS.hpp"
#include "Extension.hpp"
#include "VarDeclarationS.hpp"
#include "VarDeclaration.hpp"
#include "MethodDeclarationS.hpp"
#include "MethodDeclaration.hpp"

CASTVisualiser::CASTVisualiser(const char * filename) {
    file = fopen(filename, "w");
    fprintf(file, "digraph AST {\n");
}

CASTVisualiser::~CASTVisualiser() {
    fprintf(file, "}");
    fclose(file);
}

void CASTVisualiser::printEdge(const void * from, const void * to) const {
    fprintf(file, "\t%d -> %d;\n", (const long long)from, (const long long)to);
}

void CASTVisualiser::Visit( const CAdditionalExpressionParam* acceptable ) const {
    printEdge(acceptable, acceptable->expression);
    acceptable->expression->Accept(this);
}

void CASTVisualiser::Visit( const CAdditionalExpressionParamS* acceptable ) const {
    printEdge(acceptable, acceptable->additionalExpressionParamS);
    printEdge(acceptable, acceptable->additionalExpressionParam);
    acceptable->additionalExpressionParamS->Accept(this);
    acceptable->additionalExpressionParam->Accept(this);
}

void CASTVisualiser::Visit( const CAdditionalParam* acceptable ) const {
    printEdge(acceptable, acceptable->type);
    printEdge(acceptable, acceptable->identifier);
    acceptable->type->Accept(this);
    acceptable->identifier->Accept(this);
}

void CASTVisualiser::Visit( const CAdditionalParamS* acceptable ) const {
    printEdge(acceptable, acceptable->additionalParamS);
    printEdge(acceptable, acceptable->additionalParam);
    acceptable->additionalParamS->Accept(this);
    acceptable->additionalParam->Accept(this);
}

void CASTVisualiser::Visit( const CAndExpression* acceptable ) const {
    printEdge(acceptable, acceptable->leftExpression);
    printEdge(acceptable, acceptable->rightExpression);
    acceptable->leftExpression->Accept(this);
    acceptable->rightExpression->Accept(this);
}

void CASTVisualiser::Visit( const CArrayAssignmentStatement* acceptable ) const {
    printEdge(acceptable, acceptable->arrayName);
    printEdge(acceptable, acceptable->indexExpression);
    printEdge(acceptable, acceptable->expression);
    acceptable->arrayName->Accept(this);
    acceptable->indexExpression->Accept(this);
    acceptable->expression->Accept(this);
}

void CASTVisualiser::Visit( const CBooleanType* acceptable ) const {
    ////TODO
}

void CASTVisualiser::Visit( const CClassDeclaration* acceptable ) const {
    printEdge(acceptable, acceptable->className);
    printEdge(acceptable, acceptable->extension);
    printEdge(acceptable, acceptable->varDeclarationS);
    printEdge(acceptable, acceptable->methodDeclarationS);
    acceptable->className->Accept(this);
    acceptable->extension->Accept(this);
    acceptable->varDeclarationS->Accept(this);
    acceptable->methodDeclarationS->Accept(this);
}

void CASTVisualiser::Visit( const CClassDeclarationS* acceptable ) const {
    printEdge(acceptable, acceptable->classDeclarationS);
    printEdge(acceptable, acceptable->classDeclaration);
    acceptable->classDeclarationS->Accept(this);
    acceptable->classDeclaration->Accept(this);
}

void CASTVisualiser::Visit( const CCurlyBraceStatement* acceptable ) const {
    printEdge(acceptable, acceptable->statementS);
    acceptable->statementS->Accept(this);
}

void CASTVisualiser::Visit( const CCustomType* acceptable ) const {
    printEdge(acceptable, acceptable->typeName);
    acceptable->typeName->Accept(this);
}

void CASTVisualiser::Visit( const CDotExpression* acceptable ) const {
    printEdge(acceptable, acceptable->expression);
    printEdge(acceptable, acceptable->identifier);
    printEdge(acceptable, acceptable->expressionParamS);
    acceptable->expression->Accept(this);
    acceptable->identifier->Accept(this);
    acceptable->expressionParamS->Accept(this);
}

void CASTVisualiser::Visit( const CExpressionParamS* acceptable ) const {
    printEdge(acceptable, acceptable->expression);
    printEdge(acceptable, acceptable->addittionalExpressionParamS);
    acceptable->expression->Accept(this);
    acceptable->addittionalExpressionParamS->Accept(this);
}

void CASTVisualiser::Visit( const CExtension* acceptable ) const {
    printEdge(acceptable, acceptable->className);
    acceptable->className->Accept(this);
}

void CASTVisualiser::Visit( const CFalseExpression* acceptable ) const {
    ////TODO
}

void CASTVisualiser::Visit( const CGoal* acceptable ) const {
    printEdge(acceptable, acceptable->mainClass);
    printEdge(acceptable, acceptable->classDeclarationS);
    acceptable->mainClass->Accept(this);
    acceptable->classDeclarationS->Accept(this);
}

void CASTVisualiser::Visit( const CIdentifierExpression* acceptable ) const {
    printEdge(acceptable, acceptable->identifier);
    acceptable->identifier->Accept(this);
}

void CASTVisualiser::Visit( const CIfElseStatement* acceptable ) const {
    printEdge(acceptable, acceptable->condition);
    printEdge(acceptable, acceptable->ifStatement);
    printEdge(acceptable, acceptable->elseStatement);
    acceptable->condition->Accept(this);
    acceptable->ifStatement->Accept(this);
    acceptable->elseStatement->Accept(this);
}

void CASTVisualiser::Visit( const CIntArrayType* acceptable ) const {
    ////TODO
}

void CASTVisualiser::Visit( const CIntliteralExpression* acceptable ) const {
    printEdge(acceptable, acceptable->intliteral);
    acceptable->intliteral->Accept(this);
}

void CASTVisualiser::Visit( const CIntType* acceptable ) const {
    ////TODO
}

void CASTVisualiser::Visit( const CLengthExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CLessExpression* acceptable ) const {
    if( acceptable->leftExpression ) {
        printEdge( acceptable, acceptable->leftExpression );
        acceptable->leftExpression->Accept( this );
    }
    if( acceptable->rightExpression ) {
        printEdge( acceptable, acceptable->rightExpression );
        acceptable->rightExpression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CMainClass* acceptable ) const {
    if( acceptable->className ) {
        printEdge( acceptable, acceptable->className );
        acceptable->className->Accept( this );
    }
    if( acceptable->argName ) {
        printEdge( acceptable, acceptable->argName );
        acceptable->argName->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        acceptable->statementS->Accept( this );
    }
}

void CASTVisualiser::Visit( const CMethodDeclaration* acceptable ) const {
    if( acceptable->returnType ) {
        printEdge( acceptable, acceptable->returnType );
        acceptable->returnType->Accept( this );
    }
    if( acceptable->methodIdentifier ) {
        printEdge( acceptable, acceptable->methodIdentifier );
        acceptable->methodIdentifier->Accept( this );
    }
    if( acceptable->params ) {
        printEdge( acceptable, acceptable->params );
        acceptable->params->Accept( this );
    }
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        acceptable->statementS->Accept( this );
    }
    if( acceptable->returnExpression ) {
        printEdge( acceptable, acceptable->returnExpression );
        acceptable->returnExpression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CMethodDeclarationS* acceptable ) const {
    if( acceptable->methodDeclarationS ) {
        printEdge( acceptable, acceptable->methodDeclarationS );
        acceptable->methodDeclarationS->Accept( this );
    }
    if( acceptable->methodDeclaration ) {
        printEdge( acceptable, acceptable->methodDeclaration );
        acceptable->methodDeclaration->Accept( this );
    }
}

void CASTVisualiser::Visit( const CMinusExpression* acceptable ) const {
    if( acceptable->leftExpression ) {
        printEdge( acceptable, acceptable->leftExpression );
        acceptable->leftExpression->Accept( this );
    }
    if( acceptable->rightExpression ) {
        printEdge( acceptable, acceptable->rightExpression );
        acceptable->rightExpression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CMultiplyExpression* acceptable ) const {
    if( acceptable->leftExpression ) {
        printEdge( acceptable, acceptable->leftExpression );
        acceptable->leftExpression->Accept( this );
    }
    if( acceptable->rightExpression ) {
        printEdge( acceptable, acceptable->rightExpression );
        acceptable->rightExpression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CNewArrayExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CNewIdentifierExpression* acceptable ) const {
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
}

void CASTVisualiser::Visit( const CNotExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CParams* acceptable ) const {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    if( acceptable->additionalParamS ) {
        printEdge( acceptable, acceptable->additionalParamS );
        acceptable->additionalParamS->Accept( this );
    }
}

void CASTVisualiser::Visit( const CParensExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CPlusExpression* acceptable ) const {
    if( acceptable->leftExpression ) {
        printEdge( acceptable, acceptable->leftExpression );
        acceptable->leftExpression->Accept( this );
    }
    if( acceptable->rightExpression ) {
        printEdge( acceptable, acceptable->rightExpression );
        acceptable->rightExpression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CPrintlnStatement* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CSquarebracketsExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    if( acceptable->squarebraketsExpression ) {
        printEdge( acceptable, acceptable->squarebraketsExpression );
        acceptable->squarebraketsExpression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CStatementS* acceptable ) const {
    if( acceptable->statement ) {
        printEdge( acceptable, acceptable->statement );
        acceptable->statement->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        acceptable->statementS->Accept( this );
    }
}

void CASTVisualiser::Visit( const CTerminalIdentifier* acceptable ) const {

}

void CASTVisualiser::Visit( const CTerminalIntliteral* acceptable ) const {

}

void CASTVisualiser::Visit( const CThisExpression* acceptable ) const {

}

void CASTVisualiser::Visit( const CTrueExpression* acceptable ) const {

}

void CASTVisualiser::Visit( const CVarAssignmentStatement* acceptable ) const {
    if( acceptable->varName ) {
        printEdge( acceptable, acceptable->varName );
        acceptable->varName->Accept( this );
    }
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
}

void CASTVisualiser::Visit( const CVarDeclaration* acceptable ) const {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
}

void CASTVisualiser::Visit( const CVarDeclarationS* acceptable ) const {
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->varDeclaration ) {
        printEdge(acceptable, acceptable->varDeclaration);
        acceptable->varDeclaration->Accept(this);
    }
}

void CASTVisualiser::Visit( const CWhileStatement* acceptable ) const {
    if( acceptable->condition ) {
        printEdge( acceptable, acceptable->condition );
        acceptable->condition->Accept( this );
    }
    if( acceptable->statement ) {
        printEdge( acceptable, acceptable->statement );
        acceptable->statement->Accept( this );
    }
}
