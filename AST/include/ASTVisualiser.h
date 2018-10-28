#ifndef MINIJAVACOMPILER_ASTVISUALISER_H
#define MINIJAVACOMPILER_ASTVISUALISER_H

#include "../interfaces/IVisitor.h"
#include <string>
#include <cstdio>

class CASTVisualiser : public IVisitor {
public:
    CASTVisualiser(const char *);
    ~CASTVisualiser();
    void printEdge(const void *,const void *);
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
    void Visit( const CLengthExpression* acceptable );
    void Visit( const CLessExpression* acceptable );
    void Visit( const CMainClass* acceptable );
    void Visit( const CMethodDeclaration* acceptable );
    void Visit( const CMethodDeclarationS* acceptable );
    void Visit( const CMinusExpression* acceptable );
    void Visit( const CMultiplyExpression* acceptable );
    void Visit( const CNewArrayExpression* acceptable );
    void Visit( const CNewIdentifierExpression* acceptable );
    void Visit( const CNotExpression* acceptable );
    void Visit( const CParams* acceptable );
    void Visit( const CParensExpression* acceptable );
    void Visit( const CPlusExpression* acceptable );
    void Visit( const CPrintlnStatement* acceptable );
    void Visit( const CSquarebracketsExpression* acceptable );
    void Visit( const CStatementS* acceptable );
    void Visit( const CTerminalIdentifier* acceptable );
    void Visit( const CTerminalIntliteral* acceptable );
    void Visit( const CThisExpression* acceptable );
    void Visit( const CTrueExpression* acceptable );
    void Visit( const CVarAssignmentStatement* acceptable );
    void Visit( const CVarDeclaration* acceptable );
    void Visit( const CVarDeclarationS* acceptable );
    void Visit( const CWhileStatement* acceptable );

private:
    FILE* file;
};

#endif //MINIJAVACOMPILER_ASTVISUALISER_H
