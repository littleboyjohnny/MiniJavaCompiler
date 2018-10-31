#include <string>

#include "ASTBuilder.h"

#include "AdditionalExpressionParam.hpp"
#include "AdditionalExpressionParamS.hpp"
#include "AdditionalParam.hpp"
#include "AdditionalParamS.hpp"
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
#include "NewArrayExpression.hpp"
#include "NewIdentifierExpression.hpp"
#include "NotExpression.hpp"
#include "Params.hpp"
#include "Param.hpp"
#include "ParensExpression.hpp"
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
#include "BinaryOpExpression.hpp"

CASTBuilder::CASTBuilder(const char * filename) {
    file = fopen(filename, "w");
    fprintf(file, "digraph AST {\n");
}

CASTBuilder::~CASTBuilder() {
    fprintf(file, "}");
    fclose(file);
}

void CASTBuilder::addLabel(const void * pMemory, const char * label) const {
    fprintf( file, "\t%d [label=\"%s\"];\n", (const long long)pMemory, label );
}

void CASTBuilder::printEdge(const void * from, const void * to) const {
    fprintf( file, "\t%d -> %d;\n", (const long long)from, (const long long)to );
}

void CASTBuilder::Visit( const CAdditionalExpressionParam* acceptable ) const {
    if(acceptable->expression) {
        printEdge(listHeadsExpressionParams.back(), acceptable->expression);
        acceptable->expression->Accept(this);
    }
}

void CASTBuilder::Visit( const CAdditionalExpressionParamS* acceptable ) const {
    if (acceptable->additionalExpressionParamS) {
        acceptable->additionalExpressionParamS->Accept(this);
    }
    if (acceptable->additionalExpressionParam) {
        acceptable->additionalExpressionParam->Accept(this);
    }
}

void CASTBuilder::Visit( const CAdditionalParam* acceptable ) const {
    if (acceptable->param) {
        printEdge(headParams, acceptable->param);
        acceptable->param->Accept(this);
    }
}

void CASTBuilder::Visit( const CAdditionalParamS* acceptable ) const {
    if (acceptable->additionalParamS) {
        acceptable->additionalParamS->Accept(this);
    }
    if (acceptable->additionalParam) {
        acceptable->additionalParam->Accept(this);
    }
}

void CASTBuilder::Visit( const CArrayAssignmentStatement* acceptable ) const {
    if (acceptable->arrayName) {
        printEdge(acceptable, acceptable->arrayName);
        acceptable->arrayName->Accept(this);
    }
    if (acceptable->indexExpression) {
        printEdge(acceptable, acceptable->indexExpression);
        acceptable->indexExpression->Accept(this);
    }
    if (acceptable->expression) {
        printEdge(acceptable, acceptable->expression);
        acceptable->expression->Accept(this);
    }
    addLabel(acceptable, "ArrayAssignmentStatement");
}

void CASTBuilder::Visit( const CBooleanType* acceptable ) const {
    addLabel(acceptable, "boolean");
}

void CASTBuilder::Visit( const CClassDeclaration* acceptable ) const {
    if (acceptable->className) {
        printEdge(acceptable, acceptable->className);
        acceptable->className->Accept(this);
    }
    if (acceptable->extension) {
        printEdge(acceptable, acceptable->extension);
        acceptable->extension->Accept(this);
    }
    if (acceptable->varDeclarationS) {
        printEdge(acceptable, acceptable->varDeclarationS);
        headVarDeclarationS = acceptable->varDeclarationS;
        addLabel(headVarDeclarationS, "VarDeclarationS");
        acceptable->varDeclarationS->Accept(this);
    }
    if (acceptable->methodDeclarationS) {
        printEdge(acceptable, acceptable->methodDeclarationS);
        headMethodDeclarationS = acceptable->methodDeclarationS;
        addLabel(headMethodDeclarationS, "MethodDeclarationS");
        acceptable->methodDeclarationS->Accept(this);
    }
    addLabel(acceptable, "ClassDeclaration");
}

void CASTBuilder::Visit( const CClassDeclarationS* acceptable ) const {
    if (acceptable->classDeclarationS) {
        acceptable->classDeclarationS->Accept(this);
    }
    if (acceptable->classDeclaration) {
        printEdge(headClassDeclarationS, acceptable->classDeclaration);
        acceptable->classDeclaration->Accept(this);
    }
}

void CASTBuilder::Visit( const CCurlyBraceStatement* acceptable ) const {
    if (acceptable->statementS) {
        printEdge(acceptable, acceptable->statementS);
        listHeadsStatements.push_back(acceptable->statementS);
        acceptable->statementS->Accept(this);
    }
    addLabel(acceptable, "CurlyBraceStatement");
}

void CASTBuilder::Visit( const CCustomType* acceptable ) const {
    if (acceptable->typeName) {
        printEdge(acceptable, acceptable->typeName);
        acceptable->typeName->Accept(this);
    }
    addLabel(acceptable, "CustomType");
}

void CASTBuilder::Visit( const CCallExpression* acceptable ) const {
    if (acceptable->expression) {
        printEdge(acceptable, acceptable->expression);
        acceptable->expression->Accept(this);
    }
    if (acceptable->identifier) {
        printEdge(acceptable, acceptable->identifier);
        acceptable->identifier->Accept(this);
    }
    if (acceptable->expressionParamS) {
        printEdge(acceptable, acceptable->expressionParamS);
        listHeadsExpressionParams.push_back(acceptable->expressionParamS);
        acceptable->expressionParamS->Accept(this);
    }
    addLabel(acceptable, "DotExpression");
}

void CASTBuilder::Visit( const CExpressionParamS* acceptable ) const {
    if (acceptable->expression) {
        printEdge(listHeadsExpressionParams.back(), acceptable->expression);
        acceptable->expression->Accept(this);
    }
    if (acceptable->addittionalExpressionParamS) {
        acceptable->addittionalExpressionParamS->Accept(this);
    }
    addLabel(listHeadsExpressionParams.back(), "ExpressionParamS");
    listHeadsExpressionParams.pop_back();
}

void CASTBuilder::Visit( const CExtension* acceptable ) const {
    if (acceptable->className) {
        printEdge(acceptable, acceptable->className);
        acceptable->className->Accept(this);
    }
    addLabel(acceptable, "Extension");
}

void CASTBuilder::Visit( const CFalseExpression* acceptable ) const {
    addLabel(acceptable, "false");
}

void CASTBuilder::Visit( const CGoal* acceptable ) const {
    if (acceptable->mainClass) {
        printEdge(acceptable, acceptable->mainClass);
        acceptable->mainClass->Accept(this);
    }
    if (acceptable->classDeclarationS) {
        printEdge(acceptable, acceptable->classDeclarationS);
        headClassDeclarationS = acceptable->classDeclarationS;
        addLabel(headClassDeclarationS, "ClassDeclarationS");
        acceptable->classDeclarationS->Accept(this);
    }
    addLabel(acceptable, "Goal");
}

void CASTBuilder::Visit( const CIdentifierExpression* acceptable ) const {
    if (acceptable->identifier) {
        printEdge(acceptable, acceptable->identifier);
        acceptable->identifier->Accept(this);
    }
    addLabel(acceptable, "IdentifierExpression");
}

void CASTBuilder::Visit( const CIfElseStatement* acceptable ) const {
    if (acceptable->condition) {
        printEdge(acceptable, acceptable->condition);
        acceptable->condition->Accept(this);
    }
    if (acceptable->ifStatement) {
        printEdge(acceptable, acceptable->ifStatement);
        acceptable->ifStatement->Accept(this);
    }
    if (acceptable->elseStatement) {
        printEdge(acceptable, acceptable->elseStatement);
        acceptable->elseStatement->Accept(this);
    }
    addLabel(acceptable, "IfElseStatement");
}

void CASTBuilder::Visit( const CIntArrayType* acceptable ) const {
    addLabel(acceptable, "int[]");
}

void CASTBuilder::Visit( const CIntliteralExpression* acceptable ) const {
    if (acceptable->intliteral) {
        printEdge(acceptable, acceptable->intliteral);
        acceptable->intliteral->Accept(this);
    }
    addLabel(acceptable, "IntliteralExpression");
}

void CASTBuilder::Visit( const CIntType* acceptable ) const {
    addLabel(acceptable, "int");
}

void CASTBuilder::Visit( const CLengthExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel(acceptable, "LengthExpression");
}

void CASTBuilder::Visit( const CMainClass* acceptable ) const {
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
        listHeadsStatements.push_back(acceptable->statementS);
        acceptable->statementS->Accept( this );
    }
    addLabel(acceptable, "MainClass");
}

void CASTBuilder::Visit( const CMethodDeclaration* acceptable ) const {
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
        headParams = acceptable->params;
        addLabel(headParams, "Params");
        acceptable->params->Accept( this );
    }
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS );
        headVarDeclarationS = acceptable->varDeclarationS;
        addLabel(headVarDeclarationS, "VarDeclarationS");
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        listHeadsStatements.push_back(acceptable->statementS);
        acceptable->statementS->Accept( this );
    }
    if( acceptable->returnExpression ) {
        printEdge( acceptable, acceptable->returnExpression );
        acceptable->returnExpression->Accept( this );
    }
    addLabel(acceptable, "MethodDeclaration");
}

void CASTBuilder::Visit( const CMethodDeclarationS* acceptable ) const {
    if (acceptable->methodDeclarationS) {
        acceptable->methodDeclarationS->Accept(this);
    }
    if (acceptable->methodDeclaration) {
        printEdge(headMethodDeclarationS, acceptable->methodDeclaration);
        acceptable->methodDeclaration->Accept(this);
    }
}

void CASTBuilder::Visit( const CNewArrayExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel(acceptable, "NewArrayExpression");
}

void CASTBuilder::Visit( const CNewIdentifierExpression* acceptable ) const {
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    addLabel(acceptable, "NewIdentifierExpression");
}

void CASTBuilder::Visit( const CNotExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel(acceptable, "NotExpression");
}

void CASTBuilder::Visit( const CParams* acceptable ) const {
    if( acceptable->param ) {
        printEdge( headParams, acceptable->param );
        acceptable->param->Accept( this );
    }
    if( acceptable->additionalParamS ) {
        acceptable->additionalParamS->Accept( this );
    }
}

void CASTBuilder::Visit( const CParam* acceptable ) const {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    addLabel(acceptable, "Param");
}

void CASTBuilder::Visit( const CParensExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel(acceptable, "ParensExpression");
}

void CASTBuilder::Visit( const CPrintlnStatement* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel(acceptable, "PrintlnStatement");
}

void CASTBuilder::Visit( const CSquarebracketsExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    if( acceptable->squarebraketsExpression ) {
        printEdge( acceptable, acceptable->squarebraketsExpression );
        acceptable->squarebraketsExpression->Accept( this );
    }
    addLabel(acceptable, "SquarebracketsExpression");
}

void CASTBuilder::Visit( const CStatementS* acceptable ) const {
    if( acceptable->statement ) {
        printEdge( listHeadsStatements.back() , acceptable->statement );
        acceptable->statement->Accept( this );
    }
    if( acceptable->statementS ) {
        acceptable->statementS->Accept( this );
    } else {
        addLabel(listHeadsStatements.back(), "StatementS");
        listHeadsStatements.pop_back();
    }
}

void CASTBuilder::Visit( const CTerminalIdentifier* acceptable ) const {
    addLabel(acceptable, acceptable->identifier);
}

void CASTBuilder::Visit( const CTerminalIntliteral* acceptable ) const {
    addLabel(acceptable, std::to_string(acceptable->intliteral).c_str());
}

void CASTBuilder::Visit( const CThisExpression* acceptable ) const {
    addLabel(acceptable, "this");
}

void CASTBuilder::Visit( const CTrueExpression* acceptable ) const {
    addLabel(acceptable, "true");
}

void CASTBuilder::Visit( const CVarAssignmentStatement* acceptable ) const {
    if( acceptable->varName ) {
        printEdge( acceptable, acceptable->varName );
        acceptable->varName->Accept( this );
    }
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel(acceptable, "VarAssignmentStatement");
}

void CASTBuilder::Visit( const CVarDeclaration* acceptable ) const {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    addLabel(acceptable, "VarDeclaration");
}

void CASTBuilder::Visit( const CVarDeclarationS* acceptable ) const {
    if (acceptable->varDeclarationS) {
        acceptable->varDeclarationS->Accept(this);
    }
    if (acceptable->varDeclaration) {
        printEdge(headVarDeclarationS, acceptable->varDeclaration);
        acceptable->varDeclaration->Accept(this);
    }
}

void CASTBuilder::Visit( const CWhileStatement* acceptable ) const {
    if( acceptable->condition ) {
        printEdge( acceptable, acceptable->condition );
        acceptable->condition->Accept( this );
    }
    if( acceptable->statement ) {
        printEdge( acceptable, acceptable->statement );
        acceptable->statement->Accept( this );
    }
    addLabel(acceptable, "WhileStatement");
}

void CASTBuilder::Visit( const CBinaryOpExpression* acceptable ) const {
    if( acceptable->left ) {
        printEdge( acceptable, acceptable->left );
        acceptable->left->Accept( this );
    }
    char str[2] = { acceptable->opType, '\0'};
    printEdge( acceptable, &acceptable->opType );
    addLabel( &acceptable->opType, str );
    if( acceptable->right ) {
        printEdge( acceptable, acceptable->right );
        acceptable->right->Accept( this );
    }
    addLabel(acceptable, "BinaryOpExpression");
}