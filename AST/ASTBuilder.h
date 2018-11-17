#pragma once

#include "core/IVisitor.h"
#include "include/ClassDeclarationList.hpp"
#include "include/StatementList.hpp"
#include "interfaces/IExpressionParamS.h"
#include <list>

class CASTBuilder : public IVisitor {
public:
    CASTBuilder();
    ~CASTBuilder();

    const CGoal* BuildAST( const CGoal * );

    void Visit( const CAdditionalExpressionParam* acceptable ) const;
    void Visit( const CAdditionalExpressionParamS* acceptable ) const;
    void Visit( const CAdditionalParam* acceptable ) const;
    void Visit( const CAdditionalParamS* acceptable ) const;
    void Visit( const CArrayAssignmentStatement* acceptable ) const;
    void Visit( const CBooleanType* acceptable ) const;
    void Visit( const CClassDeclaration* acceptable ) const;
    void Visit( const CClassDeclarationS* acceptable ) const;
    void Visit( const CClassDeclarationList* acceptable ) const;
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
    mutable const CGoal * ast;
    mutable const IAcceptable * child;
    mutable const CClassDeclarationList * headClassDeclarationS = nullptr;
    mutable const CVarDeclarationList * headVarDeclarationS = nullptr;
    mutable const CMethodDeclarationList * headMethodDeclarationS = nullptr;
    mutable const CParamList * headParams = nullptr;

    mutable std::list<const CStatementList *> listHeadsStatements;
    mutable std::list<const CExpressionParamList *> listHeadsExpressionParams;
};


