#pragma once

#include "core/IVisitor.h"
#include "include/SymbolTable.h"

class CSymbol;

class CTypeChecker : public IVisitor {
public:

    void Run( const CGoal* acceptable, CSymbolTable* _table );


    void Visit( const CArrayAssignmentStatement* acceptable );
    void Visit( const CClassDeclaration* acceptable ) final;
    void Visit( const CClassDeclarationList* acceptable ) final;
    void Visit( const CCurlyBraceStatement* acceptable ) final;
    void Visit( const CCallExpression* acceptable );
    void Visit( const CExpressionParamList* acceptable );
    void Visit( const CFalseExpression* acceptable );
    void Visit( const CGoal* acceptable ) final;
    void Visit( const CIdentifierExpression* acceptable );
    void Visit( const CIfElseStatement* acceptable ) final;
    void Visit( const CIntliteralExpression* acceptable );
    void Visit( const CLengthExpression* acceptable );
    void Visit( const CMainClass* acceptable ) final;
    void Visit( const CMethodDeclaration* acceptable ) final;
    void Visit( const CMethodDeclarationList* acceptable ) final;
    void Visit( const CNewArrayExpression* acceptable );
    void Visit( const CNewIdentifierExpression* acceptable );
    void Visit( const CNotExpression* acceptable );
    void Visit( const CParensExpression* acceptable );
    void Visit( const CPrintlnStatement* acceptable ) final;
    void Visit( const CSquarebracketsExpression* acceptable );
    void Visit( const CStatementList* acceptable ) final;
    void Visit( const CThisExpression* acceptable );
    void Visit( const CTrueExpression* acceptable );
    void Visit( const CVarAssignmentStatement* acceptable );
    void Visit( const CWhileStatement* acceptable ) final;
    void Visit( const CBinaryOpExpression* acceptable );

    // эти методы не нужны при проверке типов
    void Visit( const CAdditionalExpressionParam* acceptable ) final {};
    void Visit( const CAdditionalExpressionParamS* acceptable ) final {};
    void Visit( const CAdditionalParam* acceptable ) final {};
    void Visit( const CAdditionalParamS* acceptable ) final {};
    void Visit( const CClassDeclarationS* acceptable ) final {};
    void Visit( const CExpressionParamS* acceptable ) final {};
    void Visit( const CExtension* acceptable ) final {};
    void Visit( const CMethodDeclarationS* acceptable ) final {};
    void Visit( const CParams* acceptable ) final {};
    void Visit( const CParam* acceptable ) final {};
    void Visit( const CParamList* acceptable ) final {};
    void Visit( const CStatementS* acceptable ) final {};
    void Visit( const CVarDeclaration* acceptable ) final {};
    void Visit( const CVarDeclarationList* acceptable ) final {};
    void Visit( const CVarDeclarationS* acceptable ) final {};
    void Visit( const CTerminalIntliteral* acceptable ) final {};
    void Visit( const CTerminalIdentifier* acceptable ) final {};
    void Visit( const CType* acceptable ) final {};

private:
    CSymbolTable* table;

    static const CSymbol* const booleanSymbol;
    static const CSymbol* const intSymbol;
    static const CSymbol* const intArraySymbol;

    // вызов IExpression::Accept проставляет свой тип в эту переменную
    // если при выводе типа произошла ошибка, то - nullptr
    const CSymbol* lastExpressionType;

    // сохраняем текущий класс, нужно для this
    const CClassInfo* currentClass;
};
