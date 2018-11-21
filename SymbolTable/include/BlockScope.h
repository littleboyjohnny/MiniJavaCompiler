#pragma once

#include <unordered_map>
#include <vector>

#include "NameScope.h"
#include "Symbol.h"


class CBlockScope : public INameScope {
public:

    // набор методов добавляет переданный символ без каких либо проверок
    void AddMethod( const CSymbol* symbol, const CMethodInfo* methodInfo );
    void AddVariable( const CSymbol* symbol, const CVariableInfo* variableInfo );
    void AddClass( const CSymbol* symbol, const CClassInfo* classInfo );

    // набор методов, проверяющих, что добавляемый символ не создает конфликта имен
    bool TryAddMethod( const CSymbol* symbol, const CMethodInfo* methodInfo );
    bool TryAddVariable( const CSymbol* symbol, const CVariableInfo* variableInfo );
    bool TryAddClass( const CSymbol* symbol, const CClassInfo* classInfo );

    // возвращает тип символа, в т.ч. для еще не добавленного - UNDECLARED
    SymbolType ResolveType( const CSymbol* symbol ) const;

    // набор методов, возвращающих информацию о данных, связанных с символом,
    // либо nullptr, если символ - UNDECLARED
    const CMethodInfo* TryResolveMethod( const CSymbol* symbol ) const;
    const CVariableInfo* TryResolveVariable( const CSymbol* symbol ) const;
    const CClassInfo* TryResolveClass( const CSymbol* symbol ) const;

    // набор методов, возвращающий все имена из области видимости
    std::vector<const CSymbol*> GetMethodNames() const;
    std::vector<const CSymbol*> GetVariableNames() const;
    std::vector<const CSymbol*> GetClassNames() const;


private:
    std::unordered_map<const CSymbol*, const CMethodInfo*> methods;
    std::unordered_map<const CSymbol*, const CVariableInfo*> variables;
    std::unordered_map<const CSymbol*, const CClassInfo*> classes;
};
