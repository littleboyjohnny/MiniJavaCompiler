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
    printEdge(acceptable, acceptable->expression);
    acceptable->expression->Accept(this);
}

void CASTVisualiser::Visit( CAdditionalExpressionParamS* acceptable ) {
    printEdge(acceptable, acceptable->additionalExpressionParamS);
    printEdge(acceptable, acceptable->additionalExpressionParam);
    acceptable->additionalExpressionParamS->Accept(this);
    acceptable->additionalExpressionParam->Accept(this);
}

void CASTVisualiser::Visit( CAdditionalParam* acceptable ) {
    printEdge(acceptable, acceptable->type);
    printEdge(acceptable, acceptable->identifier);
    acceptable->type->Accept(this);
    acceptable->identifier->Accept(this);
}

void CASTVisualiser::Visit( CAdditionalParamS* acceptable ) {
    printEdge(acceptable, acceptable->additionalParamS);
    printEdge(acceptable, acceptable->additionalParam);
    acceptable->additionalParamS->Accept(this);
    acceptable->additionalParam->Accept(this);
}

void CASTVisualiser::Visit( CAndExpression* acceptable ) {
    printEdge(acceptable, acceptable->leftExpression);
    printEdge(acceptable, acceptable->rightExpression);
    acceptable->leftExpression->Accept(this);
    acceptable->rightExpression->Accept(this);
}

void CASTVisualiser::Visit( CArrayAssignmentStatement* acceptable ) {
    printEdge(acceptable, acceptable->arrayName);
    printEdge(acceptable, acceptable->indexExpression);
    printEdge(acceptable, acceptable->expression);
    acceptable->arrayName->Accept(this);
    acceptable->indexExpression->Accept(this);
    acceptable->expression->Accept(this);
}

void CASTVisualiser::Visit( CBooleanType* acceptable ) {
    ////TODO
}

void CASTVisualiser::Visit( CClassDeclaration* acceptable ) {
    printEdge(acceptable, acceptable->className);
    printEdge(acceptable, acceptable->extension);
    printEdge(acceptable, acceptable->varDeclarationS);
    printEdge(acceptable, acceptable->methodDeclarationS);
    acceptable->className->Accept(this);
    acceptable->extension->Accept(this);
    acceptable->varDeclarationS->Accept(this);
    acceptable->methodDeclarationS->Accept(this);
}

void CASTVisualiser::Visit( CClassDeclarationS* acceptable ) {
    printEdge(acceptable, acceptable->classDeclarationS);
    printEdge(acceptable, acceptable->classDeclaration);
    acceptable->classDeclarationS->Accept(this);
    acceptable->classDeclaration->Accept(this);
}

void CASTVisualiser::Visit( CCurlyBraceStatement* acceptable ) {
    printEdge(acceptable, acceptable->statementS);
    acceptable->statementS->Accept(this);
}

void CASTVisualiser::Visit( CCustomType* acceptable ) {
    printEdge(acceptable, acceptable->typeName);
    acceptable->typeName->Accept(this);
}

void CASTVisualiser::Visit( CDotExpression* acceptable ) {
    printEdge(acceptable, acceptable->expression);
    printEdge(acceptable, acceptable->identifier);
    printEdge(acceptable, acceptable->expressionParamS);
    acceptable->expression->Accept(this);
    acceptable->identifier->Accept(this);
    acceptable->expressionParamS->Accept(this);
}

void CASTVisualiser::Visit( CExpressionParamS* acceptable ) {
    printEdge(acceptable, acceptable->expression);
    printEdge(acceptable, acceptable->addittionalExpressionParamS);
    acceptable->expression->Accept(this);
    acceptable->addittionalExpressionParamS->Accept(this);
}

void CASTVisualiser::Visit( CExtension* acceptable ) {
    printEdge(acceptable, acceptable->className);
    acceptable->className->Accept(this);
}

void CASTVisualiser::Visit( CFalseExpression* acceptable ) {
    ////TODO
}

void CASTVisualiser::Visit( CGoal* acceptable ) {
    printEdge(acceptable, acceptable->mainClass);
    printEdge(acceptable, acceptable->classDeclarationS);
    acceptable->mainClass->Accept(this);
    acceptable->classDeclarationS->Accept(this);
}

void CASTVisualiser::Visit( CIdentifierExpression* acceptable ) {
    printEdge(acceptable, acceptable->identifier);
    acceptable->identifier->Accept(this);
}

void CASTVisualiser::Visit( CIfElseStatement* acceptable ) {
    printEdge(acceptable, acceptable->condition);
    printEdge(acceptable, acceptable->ifStatement);
    printEdge(acceptable, acceptable->elseStatement);
    acceptable->condition->Accept(this);
    acceptable->ifStatement->Accept(this);
    acceptable->elseStatement->Accept(this);
}

void CASTVisualiser::Visit( CIntArrayType* acceptable ) {
    ////TODO
}

void CASTVisualiser::Visit( CIntliteralExpression* acceptable ) {
    printEdge(acceptable, acceptable->intliteral);
    acceptable->intliteral->Accept(this);
}

void CASTVisualiser::Visit( CIntType* acceptable ) {
    ////TODO
}

void CASTVisualiser::Visit( CLengthExpression* acceptable ) {

}

void CASTVisualiser::Visit( CLessExpression* acceptable ) {

}

void CASTVisualiser::Visit( CMainClass* acceptable ) {

}

void CASTVisualiser::Visit( CMethodDeclaration* acceptable ) {

}

void CASTVisualiser::Visit( CMethodDeclarationS* acceptable ) {

}

void CASTVisualiser::Visit( CMinusExpression* acceptable ) {

}

void CASTVisualiser::Visit( CMultiplyExpression* acceptable ) {

}

void CASTVisualiser::Visit( CNewArrayExpression* acceptable ) {

}

void CASTVisualiser::Visit( CNewIdentifierExpression* acceptable ) {

}

void CASTVisualiser::Visit( CNotExpression* acceptable ) {

}

void CASTVisualiser::Visit( CParams* acceptable ) {

}

void CASTVisualiser::Visit( CParensExpression* acceptable ) {

}

void CASTVisualiser::Visit( CPlusExpression* acceptable ) {

}

void CASTVisualiser::Visit( CPrintlnStatement* acceptable ) {

}

void CASTVisualiser::Visit( CSquarebracketsExpression* acceptable ) {

}

void CASTVisualiser::Visit( CStatementS* acceptable ) {

}

void CASTVisualiser::Visit( CTerminalIdentifier* acceptable ) {

}

void CASTVisualiser::Visit( CTerminalIntliteral* acceptable ) {

}

void CASTVisualiser::Visit( CThisExpression* acceptable ) {

}

void CASTVisualiser::Visit( CTrueExpression* acceptable ) {

}

void CASTVisualiser::Visit( CVarAssignmentStatement* acceptable ) {

}

void CASTVisualiser::Visit( CVarDeclaration* acceptable ) {

}

void CASTVisualiser::Visit( CVarDeclarationS* acceptable ) {

}

void CASTVisualiser::Visit( CWhileStatement* acceptable ) {

}
