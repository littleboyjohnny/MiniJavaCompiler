#ifndef MINIJAVACOMPILER_ASTVISUALISER_H
#define MINIJAVACOMPILER_ASTVISUALISER_H

#include <cstdio>

#include "core/IVisitor.h"
#include "ASTPredefines.h"

class CTerminalIdentifier;
class CTerminalIntliteral;


class CASTVisualiser : public IVisitor {
public:
    CASTVisualiser( const char * );

    ~CASTVisualiser();

    void Visit( const CAdditionalExpressionParam* acceptable ) const;
    void Visit( const CAdditionalExpressionParamS* acceptable ) const;
    void Visit( const CAdditionalParam* acceptable ) const;
    void Visit( const CAdditionalParamS* acceptable ) const;
    void Visit( const CArrayAssignmentStatement* acceptable ) const;
    void Visit( const CBooleanType* acceptable ) const;
    void Visit( const CClassDeclaration* acceptable ) const;
    void Visit( const CClassDeclarationList* acceptable ) const;
    void Visit( const CClassDeclarationS* acceptable ) const;
    void Visit( const CCurlyBraceStatement* acceptable ) const;
    void Visit( const CCustomType* acceptable ) const;
    void Visit( const CCallExpression* acceptable ) const;
    void Visit( const CExpressionParamS* acceptable ) const;
    void Visit( const CExpressionParamList* acceptable ) const;
    void Visit( const CExtension* acceptable ) const;
    void Visit( const CFalseExpression* acceptable ) const;
    void Visit( const CGoal* acceptable ) const;
    void Visit( const CIdentifierExpression* acceptable ) const;
    void Visit( const CIfElseStatement* acceptable ) const;
    void Visit( const CIntArrayType* acceptable ) const;
    void Visit( const CIntliteralExpression* acceptable ) const;
    void Visit( const CIntType* acceptable ) const;
    void Visit( const CLengthExpression* acceptable ) const;
    void Visit( const CMainClass* acceptable ) const;
    void Visit( const CMethodDeclaration* acceptable ) const;
    void Visit( const CMethodDeclarationList* acceptable ) const;
    void Visit( const CMethodDeclarationS* acceptable ) const;
    void Visit( const CNewArrayExpression* acceptable ) const;
    void Visit( const CNewIdentifierExpression* acceptable ) const;
    void Visit( const CNotExpression* acceptable ) const;
    void Visit( const CParams* acceptable ) const;
    void Visit( const CParam* acceptable ) const;
    void Visit( const CParamList* acceptable ) const;
    void Visit( const CParensExpression* acceptable ) const;
    void Visit( const CPrintlnStatement* acceptable ) const;
    void Visit( const CSquarebracketsExpression* acceptable ) const;
    void Visit( const CStatementS* acceptable ) const;
    void Visit( const CStatementList* acceptable ) const;
    void Visit( const CThisExpression* acceptable ) const;
    void Visit( const CTrueExpression* acceptable ) const;
    void Visit( const CVarAssignmentStatement* acceptable ) const;
    void Visit( const CVarDeclaration* acceptable ) const;
    void Visit( const CVarDeclarationList* acceptable ) const;
    void Visit( const CVarDeclarationS* acceptable ) const;
    void Visit( const CWhileStatement* acceptable ) const;
    void Visit( const CBinaryOpExpression* acceptable ) const;

    void Visit( const CTerminalIdentifier* acceptable ) const;
    void Visit( const CTerminalIntliteral* acceptable ) const;

private:
    FILE* file;

    void printEdge( const void * from, const void * to ) const;
    void addLabel( const void * pMemory, const char * label ) const;
};

#endif //MINIJAVACOMPILER_ASTVISUALISER_H
