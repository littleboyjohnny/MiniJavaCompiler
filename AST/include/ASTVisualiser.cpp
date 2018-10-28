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

void CASTVisualiser::Visit( const CLengthExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( const CLessExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->rightExpression->Accept( this );
}

void CASTVisualiser::Visit( const CMainClass* acceptable ) {
    printEdge( acceptable, acceptable->className );
    printEdge( acceptable, acceptable->argName );
    printEdge( acceptable, acceptable->statementS );

    acceptable->className->Accept( this );
    acceptable->argName->Accept( this );
    acceptable->statementS->Accept( this );
}

void CASTVisualiser::Visit( const CMethodDeclaration* acceptable ) {
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

void CASTVisualiser::Visit( const CMethodDeclarationS* acceptable ) {
    printEdge( acceptable, acceptable->methodDeclarationS );
    printEdge( acceptable, acceptable->methodDeclaration );

    acceptable->methodDeclarationS->Accept( this );
    acceptable->methodDeclaration->Accept( this );
}

void CASTVisualiser::Visit( const CMinusExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->-rightExpression>Accept( this );
}

void CASTVisualiser::Visit( const CMultiplyExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->rightExpression->Accept( this );
}

void CASTVisualiser::Visit( const CNewArrayExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( const CNewIdentifierExpression* acceptable ) {
    printEdge( acceptable, acceptable->identifier );

    acceptable->identifier->Accept( this );
}

void CASTVisualiser::Visit( const CNotExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( const CParams* acceptable ) {
    printEdge( acceptable, acceptable->type );
    printEdge( acceptable, acceptable->identifier );
    printEdge( acceptable, acceptable->additionalParamS );

    acceptable->type->Accept( this );
    acceptable->identifier->Accept( this );
    acceptable->additionalParamS->Accept( this );
}

void CASTVisualiser::Visit( const CParensExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( const CPlusExpression* acceptable ) {
    printEdge( acceptable, acceptable->leftExpression );
    printEdge( acceptable, acceptable->rightExpression );

    acceptable->leftExpression->Accept( this );
    acceptable->rightExpression->Accept( this );
}

void CASTVisualiser::Visit( const CPrintlnStatement* acceptable ) {
    printEdge( acceptable, acceptable->expression );

    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( const CSquarebracketsExpression* acceptable ) {
    printEdge( acceptable, acceptable->expression );
    printEdge( acceptable, acceptable->squarebraketsExpression );

    acceptable->expression->Accept( this );
    acceptable->squarebraketsExpression->Accept( this );
}

void CASTVisualiser::Visit( const CStatementS* acceptable ) {
    printEdge( acceptable, acceptable->statement );
    printEdge( acceptable, acceptable->statementS );

    acceptable->statement->Accept( this );
    acceptable->statementS->Accept( this );
}

void CASTVisualiser::Visit( const CTerminalIdentifier* acceptable ) {
    printEdge( acceptable, acceptable->identifier );

    acceptable->identifier->Accept( this );
}

void CASTVisualiser::Visit( const CTerminalIntliteral* acceptable ) {
    printEdge( acceptable, acceptable->intliteral );

    acceptable->intliteral->Accept( this );
}

void CASTVisualiser::Visit( const CThisExpression* acceptable ) {

}

void CASTVisualiser::Visit( const CTrueExpression* acceptable ) {

}

void CASTVisualiser::Visit( const CVarAssignmentStatement* acceptable ) {
    printEdge( acceptable, acceptable->varName );
    printEdge( acceptable, acceptable->expression );

    acceptable->varName->Accept( this );
    acceptable->expression->Accept( this );
}

void CASTVisualiser::Visit( const CVarDeclaration* acceptable ) {
    printEdge( acceptable, acceptable->type );
    printEdge( acceptable, acceptable->identifier );

    acceptable->type->Accept( this );
    acceptable->identifier->Accept( this );
}

void CASTVisualiser::Visit( const CVarDeclarationS* acceptable ) {
    printEdge( acceptable, acceptable->varDeclarationS );
    printEdge( acceptable, acceptable->varDeclaration );

    acceptable->varDeclarationS->Accept( this );
    acceptable->varDeclaration->Accept( this );
}

void CASTVisualiser::Visit( const CWhileStatement* acceptable ) {
    printEdge( acceptable, acceptable->condition );
    printEdge( acceptable, acceptable->statement );

    acceptable->condition->Accept( this );
    acceptable->statement->Accept( this );
}
