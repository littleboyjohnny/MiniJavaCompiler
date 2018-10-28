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

void CASTVisualiser::printEdge(const char * from, const char * to) {
    fprintf(file, "\t%s -> %s;\n", from, to);
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
    printEdge("Goal", "MainClass");
    printEdge("Goal", "ClassDeclarationS");
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
