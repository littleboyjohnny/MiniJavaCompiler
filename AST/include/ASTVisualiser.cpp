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

void CASTVisualiser::printEdge(const void * from, const void * to) {
    fprintf(file, "\t%d -> %d;\n", (const long long)from, (const long long)to);
}

void CASTVisualiser::Visit( CAdditionalExpressionParam* acceptable ) {

}

void CASTVisualiser::Visit( CAdditionalExpressionParamS* acceptable ) {

}

void CASTVisualiser::Visit( CAdditionalParam* acceptable ) {

}

void CASTVisualiser::Visit( CAdditionalParamS* acceptable ) {

}

void CASTVisualiser::Visit( CAndExpression* acceptable ) {

}

void CASTVisualiser::Visit( CArrayAssignmentStatement* acceptable ) {

}

void CASTVisualiser::Visit( CBooleanType* acceptable ) {

}

void CASTVisualiser::Visit( CClassDeclaration* acceptable ) {

}

void CASTVisualiser::Visit( CClassDeclarationS* acceptable ) {

}

void CASTVisualiser::Visit( CCurlyBraceStatement* acceptable ) {

}

void CASTVisualiser::Visit( CCustomType* acceptable ) {

}

void CASTVisualiser::Visit( CDotExpression* acceptable ) {

}

void CASTVisualiser::Visit( CExpressionParamS* acceptable ) {

}

void CASTVisualiser::Visit( CExtension* acceptable ) {

}

void CASTVisualiser::Visit( CFalseExpression* acceptable ) {

}

void CASTVisualiser::Visit( CGoal* acceptable ) {
    printEdge(acceptable, acceptable->mainClass);
    printEdge(acceptable, acceptable->classDeclarationS);
}

void CASTVisualiser::Visit( CIdentifierExpression* acceptable ) {

}

void CASTVisualiser::Visit( CIfElseStatement* acceptable ) {

}

void CASTVisualiser::Visit( CIntArrayType* acceptable ) {

}

void CASTVisualiser::Visit( CIntliteralExpression* acceptable ) {

}

void CASTVisualiser::Visit( CIntType* acceptable ) {

}

void CASTVisualiser::Visit( CLengthExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( CLessExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->rightExpression->Accept( this );
}

void CASTVisualiser::Visit( CMainClass* acceptable ) {
    printEdge( acceptable, acceptable->className );
    printEdge( acceptable, acceptable->argName );
    printEdge( acceptable, acceptable->statementS );

    acceptable->className->Accept( this );
    acceptable->argName->Accept( this );
    acceptable->statementS->Accept( this );
}

void CASTVisualiser::Visit( CMethodDeclaration* acceptable ) {
    printEdge( acceptable, acceptable->returnType );
    printEdge( acceptable, acceptable->methodIdentifier );
    printEdge( acceptable, acceptable->params );
    printEdge( acceptable, acceptable->varDeclarationS );
    printEdge( acceptable, acceptable->statementS );
    printEdge( acceptable, acceptable->returnExpression );

    acceptable->returnType->Accept( this );
    acceptable->methodIdentifier->Accept( this );
    acceptable->params->Accept( this );
    acceptable->varDeclarationS->Accept( this );
    acceptable->statementS->Accept( this );
    acceptable->returnExpression->Accept( this );
}

void CASTVisualiser::Visit( CMethodDeclarationS* acceptable ) {
    printEdge( acceptable, acceptable->methodDeclarationS );
    printEdge( acceptable, acceptable->methodDeclaration );

    acceptable->methodDeclarationS->Accept( this );
    acceptable->methodDeclaration->Accept( this );
}

void CASTVisualiser::Visit( CMinusExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->-rightExpression>Accept( this );
}

void CASTVisualiser::Visit( CMultiplyExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->rightExpression->Accept( this );
}

void CASTVisualiser::Visit( CNewArrayExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( CNewIdentifierExpression* acceptable ) {
    printEdge( acceptable, acceptable->identifier );

    acceptable->identifier->Accept( this );
}

void CASTVisualiser::Visit( CNotExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( CParams* acceptable ) {
    printEdge( acceptable, acceptable->type );
    printEdge( acceptable, acceptable->identifier );
    printEdge( acceptable, acceptable->additionalParamS );

    acceptable->type->Accept( this );
    acceptable->identifier->Accept( this );
    acceptable->additionalParamS->Accept( this );
}

void CASTVisualiser::Visit( CParensExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( CPlusExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->rightExpression->Accept( this );
}

void CASTVisualiser::Visit( CPrintlnStatement* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( CSquarebracketsExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );
    printEdge( acceptable, acceptable->squarebraketsExpression );

    acceptable->expression->Accept( this );
    acceptable->squarebraketsExpression->Accept( this );
}

void CASTVisualiser::Visit( CStatementS* acceptable ) {
    printEdge( acceptable, acceptable->statement );
    printEdge( acceptable, acceptable->statementS );

    acceptable->statement->Accept( this );
    acceptable->statementS->Accept( this );
}

void CASTVisualiser::Visit( CTerminalIdentifier* acceptable ) {
    printEdge( acceptable, acceptable->identifier );

    acceptable->identifier->Accept( this );
}

void CASTVisualiser::Visit( CTerminalIntliteral* acceptable ) {
    printEdge( acceptable, acceptable->intliteral );

    acceptable->intliteral->Accept( this );
}

void CASTVisualiser::Visit( CThisExpression* acceptable ) {

}

void CASTVisualiser::Visit( CTrueExpression* acceptable ) {

}

void CASTVisualiser::Visit( CVarAssignmentStatement* acceptable ) {
    printEdge( acceptable, acceptable->varName );
    printEdge( acceptable, acceptable->expression );

    acceptable->varName->Accept( this );
    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( CVarDeclaration* acceptable ) {
    printEdge( acceptable, acceptable->type );
    printEdge( acceptable, acceptable->identifier );

    acceptable->type->Accept( this );
    acceptable->identifier->Accept( this );
}

void CASTVisualiser::Visit( CVarDeclarationS* acceptable ) {
    printEdge( acceptable, acceptable->varDeclarationS );
    printEdge( acceptable, acceptable->varDeclaration );

    acceptable->varDeclarationS->Accept( this );
    acceptable->varDeclaration->Accept( this );
}

void CASTVisualiser::Visit( CWhileStatement* acceptable ) {
    printEdge( acceptable, acceptable->condition );
    printEdge( acceptable, acceptable->statement );

    acceptable->condition->Accept( this );
    acceptable->statement->Accept( this );
}
