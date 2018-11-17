#pragma once

#include "../ASTPredefines.h"

class CTerminalIdentifier;
class CTerminalIntliteral;

class IVisitor {
public:
    virtual void Visit( const CAdditionalExpressionParam* acceptable ) = 0;
    virtual void Visit( const CAdditionalExpressionParamS* acceptable ) = 0;
    virtual void Visit( const CAdditionalParam* acceptable ) = 0;
    virtual void Visit( const CAdditionalParamS* acceptable ) = 0;
    virtual void Visit( const CArrayAssignmentStatement* acceptable ) = 0;
    virtual void Visit( const CBooleanType* acceptable ) = 0;
    virtual void Visit( const CClassDeclaration* acceptable ) = 0;
    virtual void Visit( const CClassDeclarationS* acceptable ) = 0;
    virtual void Visit( const CClassDeclarationList* acceptable ) = 0;
    virtual void Visit( const CCurlyBraceStatement* acceptable ) = 0;
    virtual void Visit( const CCustomType* acceptable ) = 0;
    virtual void Visit( const CCallExpression* acceptable ) = 0;
    virtual void Visit( const CExpressionParamS* acceptable ) = 0;
    virtual void Visit( const CExpressionParamList* acceptable ) = 0;
    virtual void Visit( const CExtension* acceptable ) = 0;
    virtual void Visit( const CFalseExpression* acceptable ) = 0;
    virtual void Visit( const CGoal* acceptable ) = 0;
    virtual void Visit( const CIdentifierExpression* acceptable ) = 0;
    virtual void Visit( const CIfElseStatement* acceptable ) = 0;
    virtual void Visit( const CIntArrayType* acceptable ) = 0;
    virtual void Visit( const CIntliteralExpression* acceptable ) = 0;
    virtual void Visit( const CIntType* acceptable ) = 0;
    virtual void Visit( const CLengthExpression* acceptable ) = 0;
    virtual void Visit( const CMainClass* acceptable ) = 0;
    virtual void Visit( const CMethodDeclaration* acceptable ) = 0;
    virtual void Visit( const CMethodDeclarationList* acceptable ) = 0;
    virtual void Visit( const CMethodDeclarationS* acceptable ) = 0;
    virtual void Visit( const CNewArrayExpression* acceptable ) = 0;
    virtual void Visit( const CNewIdentifierExpression* acceptable ) = 0;
    virtual void Visit( const CNotExpression* acceptable ) = 0;
    virtual void Visit( const CParams* acceptable ) = 0;
    virtual void Visit( const CParam* acceptable ) = 0;
    virtual void Visit( const CParamList* acceptable ) = 0;
    virtual void Visit( const CParensExpression* acceptable ) = 0;
    virtual void Visit( const CPrintlnStatement* acceptable ) = 0;
    virtual void Visit( const CSquarebracketsExpression* acceptable ) = 0;
    virtual void Visit( const CStatementS* acceptable ) = 0;
    virtual void Visit( const CStatementList* acceptable ) = 0;
    virtual void Visit( const CThisExpression* acceptable ) = 0;
    virtual void Visit( const CTrueExpression* acceptable ) = 0;
    virtual void Visit( const CVarAssignmentStatement* acceptable ) = 0;
    virtual void Visit( const CVarDeclaration* acceptable ) = 0;
    virtual void Visit( const CVarDeclarationList* acceptable ) = 0;
    virtual void Visit( const CVarDeclarationS* acceptable ) = 0;
    virtual void Visit( const CWhileStatement* acceptable ) = 0;
    virtual void Visit( const CBinaryOpExpression* acceptable ) = 0;

    virtual void Visit( const CTerminalIdentifier* acceptable ) = 0;
    virtual void Visit( const CTerminalIntliteral* acceptable ) = 0;

};

