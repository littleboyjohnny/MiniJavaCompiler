#pragma once

#include "core/IVisitor.h"
#include "include/SymbolTable.h"
#include "include/BlockScope.h"

#include <vector>
#include <memory>

class CSymbolTableBuilder : public IVisitor {
public:
    CSymbolTableBuilder();
    ~CSymbolTableBuilder();

    std::unique_ptr<CSymbolTable> Build( const CGoal* acceptable );

    void Visit( const CGoal* acceptable ) final;
    void Visit( const CMainClass* acceptable ) final;
    void Visit( const CClassDeclarationList* acceptable ) final;
    void Visit( const CClassDeclaration* acceptable ) final;
    void Visit( const CMethodDeclarationList* acceptable ) final;
    void Visit( const CMethodDeclaration* acceptable ) final;
    void Visit( const CVarDeclarationList* acceptable ) final;
    void Visit( const CVarDeclaration* acceptable ) final;
    void Visit( const CParamList* acceptable ) final;
    void Visit( const CParam* acceptable ) final;
    void Visit( const CExtension* acceptable ) final;

    // эти методы не нужны для построения таблицы символов
    void Visit( const CAdditionalExpressionParam* acceptable ) final {};
    void Visit( const CAdditionalExpressionParamS* acceptable ) final {};
    void Visit( const CAdditionalParam* acceptable ) final {};
    void Visit( const CAdditionalParamS* acceptable ) final {};
    void Visit( const CArrayAssignmentStatement* acceptable ) final {};
    void Visit( const CClassDeclarationS* acceptable ) final {};
    void Visit( const CCurlyBraceStatement* acceptable ) final {};
    void Visit( const CCallExpression* acceptable ) final {};
    void Visit( const CExpressionParamS* acceptable ) final {};
    void Visit( const CExpressionParamList* acceptable ) final {};
    void Visit( const CIdentifierExpression* acceptable ) final {};
    void Visit( const CIfElseStatement* acceptable ) final {};
    void Visit( const CIntliteralExpression* acceptable ) final {};
    void Visit( const CLengthExpression* acceptable ) final {};
    void Visit( const CMethodDeclarationS* acceptable ) final {};
    void Visit( const CNewArrayExpression* acceptable ) final {};
    void Visit( const CNewIdentifierExpression* acceptable ) final {};
    void Visit( const CNotExpression* acceptable ) final {};
    void Visit( const CParams* acceptable ) final {};
    void Visit( const CParensExpression* acceptable ) final {};
    void Visit( const CPrintlnStatement* acceptable ) final {};
    void Visit( const CSquarebracketsExpression* acceptable ) final {};
    void Visit( const CStatementS* acceptable ) final {};
    void Visit( const CStatementList* acceptable ) final {};
    void Visit( const CThisExpression* acceptable ) final {};
    void Visit( const CTrueExpression* acceptable ) final {};
    void Visit( const CFalseExpression* acceptable ) final {};
    void Visit( const CVarAssignmentStatement* acceptable ) final {};
    void Visit( const CVarDeclarationS* acceptable ) final {};
    void Visit( const CWhileStatement* acceptable ) final {};
    void Visit( const CBinaryOpExpression* acceptable ) final {};
    void Visit( const CType* acceptable ) final {};
    void Visit( const CTerminalIdentifier* acceptable ) final {};
    void Visit( const CTerminalIntliteral* acceptable ) final {};

private:
    std::vector<CBlockScope*> scopes;
    CMethodInfo* currentMethodInfo;
    CClassInfo* currentClassInfo;
    int offset;

    void onNameRedefinitionError( const CSymbol* name, const CBlockScope* scope );
};
