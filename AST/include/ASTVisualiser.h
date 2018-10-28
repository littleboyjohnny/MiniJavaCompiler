#ifndef MINIJAVACOMPILER_ASTVISUALISER_H
#define MINIJAVACOMPILER_ASTVISUALISER_H

#include "../interfaces/IVisitor.h"
#include <string>
#include <cstdio>

class CASTVisualiser : public IVisitor {
public:
    CASTVisualiser(const char *);
    ~CASTVisualiser();
    void printEdge(const char *, const char *);
    void Visit( CAdditionalExpressionParam* acceptable );
    void Visit( CAdditionalExpressionParamS* acceptable );
    void Visit( CAdditionalParam* acceptable );
    void Visit( CAdditionalParamS* acceptable );
    void Visit( CAndExpression* acceptable );
    void Visit( CArrayAssignmentStatement* acceptable );
    void Visit( CBooleanType* acceptable );
    void Visit( CClassDeclaration* acceptable );
    void Visit( CClassDeclarationS* acceptable );
    void Visit( CCurlyBraceStatement* acceptable );
    void Visit( CCustomType* acceptable );
    void Visit( CDotExpression* acceptable );
    void Visit( CExpressionParamS* acceptable );
    void Visit( CExtension* acceptable );
    void Visit( CFalseExpression* acceptable );
    void Visit( CGoal* acceptable );
    void Visit( CIdentifierExpression* acceptable );
    void Visit( CIfElseStatement* acceptable );
    void Visit( CIntArrayType* acceptable );
    void Visit( CIntliteralExpression* acceptable );
    void Visit( CIntType* acceptable );
    void Visit( CLengthExpression* acceptable );
    void Visit( CLessExpression* acceptable );
    void Visit( CMainClass* acceptable );
    void Visit( CMethodDeclaration* acceptable );
    void Visit( CMethodDeclarationS* acceptable );
    void Visit( CMinusExpression* acceptable );
    void Visit( CMultiplyExpression* acceptable );
    void Visit( CNewArrayExpression* acceptable );
    void Visit( CNewIdentifierExpression* acceptable );
    void Visit( CNotExpression* acceptable );
    void Visit( CParams* acceptable );
    void Visit( CParensExpression* acceptable );
    void Visit( CPlusExpression* acceptable );
    void Visit( CPrintlnStatement* acceptable );
    void Visit( CSquarebracketsExpression* acceptable );
    void Visit( CStatementS* acceptable );
    void Visit( CTerminalIdentifier* acceptable );
    void Visit( CTerminalIntliteral* acceptable );
    void Visit( CThisExpression* acceptable );
    void Visit( CTrueExpression* acceptable );
    void Visit( CVarAssignmentStatement* acceptable );
    void Visit( CVarDeclaration* acceptable );
    void Visit( CVarDeclarationS* acceptable );
    void Visit( CWhileStatement* acceptable );

private:
    FILE* file;
};

#endif //MINIJAVACOMPILER_ASTVISUALISER_H
