#ifndef COMPILERAST_IVISITOR_H
#define COMPILERAST_IVISITOR_H

#include "../include/ASTPredefines.h"

class CTerminalIdentifier;
class CTerminalIntliteral;

class IVisitor {
public:
    virtual void Visit( const CAdditionalExpressionParam* acceptable ) const = 0;
    virtual void Visit( const CAdditionalExpressionParamS* acceptable ) const = 0;
    virtual void Visit( const CAdditionalParam* acceptable ) const = 0;
    virtual void Visit( const CAdditionalParamS* acceptable ) const = 0;
    virtual void Visit( const CArrayAssignmentStatement* acceptable ) const = 0;
    virtual void Visit( const CBooleanType* acceptable ) const = 0;
    virtual void Visit( const CClassDeclaration* acceptable ) const = 0;
    virtual void Visit( const CClassDeclarationS* acceptable ) const = 0;
    virtual void Visit( const CClassDeclarationList* acceptable ) const = 0;
    virtual void Visit( const CCurlyBraceStatement* acceptable ) const = 0;
    virtual void Visit( const CCustomType* acceptable ) const = 0;
    virtual void Visit( const CCallExpression* acceptable ) const = 0;
    virtual void Visit( const CExpressionParamS* acceptable ) const = 0;
    virtual void Visit( const CExpressionParamList* acceptable ) const = 0;
    virtual void Visit( const CExtension* acceptable ) const = 0;
    virtual void Visit( const CFalseExpression* acceptable ) const = 0;
    virtual void Visit( const CGoal* acceptable ) const = 0;
    virtual void Visit( const CIdentifierExpression* acceptable ) const = 0;
    virtual void Visit( const CIfElseStatement* acceptable ) const = 0;
    virtual void Visit( const CIntArrayType* acceptable ) const = 0;
    virtual void Visit( const CIntliteralExpression* acceptable ) const = 0;
    virtual void Visit( const CIntType* acceptable ) const = 0;
    virtual void Visit( const CLengthExpression* acceptable ) const = 0;
    virtual void Visit( const CMainClass* acceptable ) const = 0;
    virtual void Visit( const CMethodDeclaration* acceptable ) const = 0;
    virtual void Visit( const CMethodDeclarationList* acceptable ) const = 0;
    virtual void Visit( const CMethodDeclarationS* acceptable ) const = 0;
    virtual void Visit( const CNewArrayExpression* acceptable ) const = 0;
    virtual void Visit( const CNewIdentifierExpression* acceptable ) const = 0;
    virtual void Visit( const CNotExpression* acceptable ) const = 0;
    virtual void Visit( const CParams* acceptable ) const = 0;
    virtual void Visit( const CParam* acceptable ) const = 0;
    virtual void Visit( const CParamList* acceptable ) const = 0;
    virtual void Visit( const CParensExpression* acceptable ) const = 0;
    virtual void Visit( const CPrintlnStatement* acceptable ) const = 0;
    virtual void Visit( const CSquarebracketsExpression* acceptable ) const = 0;
    virtual void Visit( const CStatementS* acceptable ) const = 0;
    virtual void Visit( const CStatementList* acceptable ) const = 0;
    virtual void Visit( const CThisExpression* acceptable ) const = 0;
    virtual void Visit( const CTrueExpression* acceptable ) const = 0;
    virtual void Visit( const CVarAssignmentStatement* acceptable ) const = 0;
    virtual void Visit( const CVarDeclaration* acceptable ) const = 0;
    virtual void Visit( const CVarDeclarationList* acceptable ) const = 0;
    virtual void Visit( const CVarDeclarationS* acceptable ) const = 0;
    virtual void Visit( const CWhileStatement* acceptable ) const = 0;
    virtual void Visit( const CBinaryOpExpression* acceptable ) const = 0;

    virtual void Visit( const CTerminalIdentifier* acceptable ) const = 0;
    virtual void Visit( const CTerminalIntliteral* acceptable ) const = 0;

};

#endif