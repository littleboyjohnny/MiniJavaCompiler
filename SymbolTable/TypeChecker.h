#pragma once

#include "core/IVisitor.h"
#include "include/SymbolTable.h"

class CSymbol;

class TypeChecker : public IVisitor {
public:

    void Run( const CGoal* acceptable, CSymbolTable* _table );

    void Visit( const CAdditionalExpressionParam* acceptable );
    void Visit( const CAdditionalExpressionParamS* acceptable );
    void Visit( const CAdditionalParam* acceptable );
    void Visit( const CAdditionalParamS* acceptable );
    void Visit( const CArrayAssignmentStatement* acceptable );
    void Visit( const CClassDeclaration* acceptable ) final;
    void Visit( const CClassDeclarationS* acceptable );
    void Visit( const CClassDeclarationList* acceptable ) final;
    void Visit( const CCurlyBraceStatement* acceptable ) final;
    void Visit( const CCallExpression* acceptable );
    void Visit( const CExpressionParamS* acceptable );
    void Visit( const CExpressionParamList* acceptable );
    void Visit( const CExtension* acceptable );
    void Visit( const CFalseExpression* acceptable );
    void Visit( const CGoal* acceptable ) final;
    void Visit( const CIdentifierExpression* acceptable );
    void Visit( const CIfElseStatement* acceptable ) final;
    void Visit( const CIntliteralExpression* acceptable );
    void Visit( const CLengthExpression* acceptable );
    void Visit( const CMainClass* acceptable ) final;
    void Visit( const CMethodDeclaration* acceptable ) final;
    void Visit( const CMethodDeclarationList* acceptable ) final;
    void Visit( const CMethodDeclarationS* acceptable );
    void Visit( const CNewArrayExpression* acceptable );
    void Visit( const CNewIdentifierExpression* acceptable );
    void Visit( const CNotExpression* acceptable );
    void Visit( const CParams* acceptable );
    void Visit( const CParam* acceptable );
    void Visit( const CParamList* acceptable );
    void Visit( const CParensExpression* acceptable );
    void Visit( const CPrintlnStatement* acceptable ) final;
    void Visit( const CSquarebracketsExpression* acceptable );
    void Visit( const CStatementS* acceptable );
    void Visit( const CStatementList* acceptable ) final;
    void Visit( const CThisExpression* acceptable );
    void Visit( const CTrueExpression* acceptable );
    void Visit( const CVarAssignmentStatement* acceptable );
    void Visit( const CVarDeclaration* acceptable );
    void Visit( const CVarDeclarationList* acceptable );
    void Visit( const CVarDeclarationS* acceptable );
    void Visit( const CWhileStatement* acceptable ) final;
    void Visit( const CBinaryOpExpression* acceptable );

    void Visit( const CTerminalIntliteral* acceptable );
    void Visit( const CTerminalIdentifier* acceptable );

    void Visit( const CType* acceptable );

private:
    CSymbolTable* table;

    static const CSymbol* const booleanSymbol;
    static const CSymbol* const intSymbol;
    static const CSymbol* const intArraySymbol;

    // вызов IExpression::Accept добавляет тип свой тип в вектор
    // если при выводе типа произошла ошибка, то - nullptr
    // сторона, использующая этот тип и инициализировавшая его выведение
    // обязана извлечь этот элемент/элементы
    std::vector<const CSymbol*> expressionTypes;

    // сохраняем текущий класс, нужно для this
    const CClassInfo* currentClass;
};
