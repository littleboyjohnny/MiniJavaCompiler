#ifndef MINIJAVACOMPILER_ASTVISUALISER_H
#define MINIJAVACOMPILER_ASTVISUALISER_H

#include "../interfaces/IVisitor.h"
#include <string>
#include <cstdio>

class CASTVisualiser : public IVisitor {
public:
    CASTVisualiser( const char * );
    ~CASTVisualiser();
    void printEdge( const void *,const void * ) const;
    void addLabel( const void *, const char * ) const;
    void Visit( const CAdditionalExpressionParam* acceptable ) const;
    void Visit( const CAdditionalExpressionParamS* acceptable ) const;
    void Visit( const CAdditionalParam* acceptable ) const;
    void Visit( const CAdditionalParamS* acceptable ) const;
    void Visit( const CAndExpression* acceptable ) const;
    void Visit( const CArrayAssignmentStatement* acceptable ) const;
    void Visit( const CBooleanType* acceptable ) const;
    void Visit( const CClassDeclaration* acceptable ) const;
    void Visit( const CClassDeclarationS* acceptable ) const;
    void Visit( const CCurlyBraceStatement* acceptable ) const;
    void Visit( const CCustomType* acceptable ) const;
    void Visit( const CDotExpression* acceptable ) const;
    void Visit( const CExpressionParamS* acceptable ) const;
    void Visit( const CExtension* acceptable ) const;
    void Visit( const CFalseExpression* acceptable ) const;
    void Visit( const CGoal* acceptable ) const;
    void Visit( const CIdentifierExpression* acceptable ) const;
    void Visit( const CIfElseStatement* acceptable ) const;
    void Visit( const CIntArrayType* acceptable ) const;
    void Visit( const CIntliteralExpression* acceptable ) const;
    void Visit( const CIntType* acceptable ) const;
    void Visit( const CLengthExpression* acceptable ) const;
    void Visit( const CLessExpression* acceptable ) const;
    void Visit( const CMainClass* acceptable ) const;
    void Visit( const CMethodDeclaration* acceptable ) const;
    void Visit( const CMethodDeclarationS* acceptable ) const;
    void Visit( const CMinusExpression* acceptable ) const;
    void Visit( const CMultiplyExpression* acceptable ) const;
    void Visit( const CNewArrayExpression* acceptable ) const;
    void Visit( const CNewIdentifierExpression* acceptable ) const;
    void Visit( const CNotExpression* acceptable ) const;
    void Visit( const CParams* acceptable ) const;
    void Visit( const CParensExpression* acceptable ) const;
    void Visit( const CPlusExpression* acceptable ) const;
    void Visit( const CPrintlnStatement* acceptable ) const;
    void Visit( const CSquarebracketsExpression* acceptable ) const;
    void Visit( const CStatementS* acceptable ) const;
    void Visit( const CThisExpression* acceptable ) const;
    void Visit( const CTrueExpression* acceptable ) const;
    void Visit( const CVarAssignmentStatement* acceptable ) const;
    void Visit( const CVarDeclaration* acceptable ) const;
    void Visit( const CVarDeclarationS* acceptable ) const;
    void Visit( const CWhileStatement* acceptable ) const;

    void Visit( const CTerminalIdentifier* acceptable ) const;
    void Visit( const CTerminalIntliteral* acceptable ) const;
    void Visit( const CTerminalAnd* acceptable ) const;
    void Visit( const CTerminalFalse* acceptable ) const;
    void Visit( const CTerminalLess* acceptable ) const;
    void Visit( const CTerminalMinus* acceptable ) const;
    void Visit( const CTerminalMultiply* acceptable ) const;
    void Visit( const CTerminalPlus* acceptable ) const;
    void Visit( const CTerminalThis* acceptable ) const;
    void Visit( const CTerminalTrue* acceptable ) const;

private:
    FILE* file;
};

#endif //MINIJAVACOMPILER_ASTVISUALISER_H
