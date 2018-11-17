#pragma once

#include <cstdio>

#include "core/IVisitor.h"
#include "ASTPredefines.h"

class CTerminalIdentifier;
class CTerminalIntliteral;


class CASTVisualiser : public IVisitor {
public:
    CASTVisualiser( const char * );

    ~CASTVisualiser();

    void Visit( const CAdditionalExpressionParam* acceptable );
    void Visit( const CAdditionalExpressionParamS* acceptable );
    void Visit( const CAdditionalParam* acceptable );
    void Visit( const CAdditionalParamS* acceptable );
    void Visit( const CArrayAssignmentStatement* acceptable );
    void Visit( const CBooleanType* acceptable );
    void Visit( const CClassDeclaration* acceptable );
    void Visit( const CClassDeclarationList* acceptable );
    void Visit( const CClassDeclarationS* acceptable );
    void Visit( const CCurlyBraceStatement* acceptable );
    void Visit( const CCustomType* acceptable );
    void Visit( const CCallExpression* acceptable );
    void Visit( const CExpressionParamS* acceptable );
    void Visit( const CExpressionParamList* acceptable );
    void Visit( const CExtension* acceptable );
    void Visit( const CFalseExpression* acceptable );
    void Visit( const CGoal* acceptable );
    void Visit( const CIdentifierExpression* acceptable );
    void Visit( const CIfElseStatement* acceptable );
    void Visit( const CIntArrayType* acceptable );
    void Visit( const CIntliteralExpression* acceptable );
    void Visit( const CIntType* acceptable );
    void Visit( const CLengthExpression* acceptable );
    void Visit( const CMainClass* acceptable );
    void Visit( const CMethodDeclaration* acceptable );
    void Visit( const CMethodDeclarationList* acceptable );
    void Visit( const CMethodDeclarationS* acceptable );
    void Visit( const CNewArrayExpression* acceptable );
    void Visit( const CNewIdentifierExpression* acceptable );
    void Visit( const CNotExpression* acceptable );
    void Visit( const CParams* acceptable );
    void Visit( const CParam* acceptable );
    void Visit( const CParamList* acceptable );
    void Visit( const CParensExpression* acceptable );
    void Visit( const CPrintlnStatement* acceptable );
    void Visit( const CSquarebracketsExpression* acceptable );
    void Visit( const CStatementS* acceptable );
    void Visit( const CStatementList* acceptable );
    void Visit( const CThisExpression* acceptable );
    void Visit( const CTrueExpression* acceptable );
    void Visit( const CVarAssignmentStatement* acceptable );
    void Visit( const CVarDeclaration* acceptable );
    void Visit( const CVarDeclarationList* acceptable );
    void Visit( const CVarDeclarationS* acceptable );
    void Visit( const CWhileStatement* acceptable );
    void Visit( const CBinaryOpExpression* acceptable );

    void Visit( const CTerminalIdentifier* acceptable );
    void Visit( const CTerminalIntliteral* acceptable );

private:
    FILE* file;

    void printEdge( const void * from, const void * to );
    void addLabel( const void * pMemory, const char * label );
};


