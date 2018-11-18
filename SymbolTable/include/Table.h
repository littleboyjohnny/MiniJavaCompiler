#pragma once

#include <vector>
#include <memory>

#include "NameScope.h"
#include "BlockScope.h"
#include "Symbol.h"
#include "MethodInfo.h"
#include "VariableInfo.h"
#include "ClassInfo.h"


class CTable : public INameScope {
public:

    // создает новый блок области видимости
    void AddNewBlockScope();

    // набор методов добавляет переданный символ без каких либо проверок
    void AddMethod( const CSymbol* symbol, const CMethodInfo* methodInfo );
    void AddVariable( const CSymbol* symbol, const CVariableInfo* variableInfo );
    void AddClass( const CSymbol* symbol, const CClassInfo* classInfo );

    // набор методов, проверяющих, что добавляемый символ не создает конфликта имен
    bool TryAddMethod( const CSymbol* symbol, const CMethodInfo* methodInfo );
    bool TryAddVariable( const CSymbol* symbol, const CVariableInfo* variableInfo );
    bool TryAddClass( const CSymbol* symbol, const CClassInfo* classInfo );

    // возвращает тип символа, в т.ч. для еще не добавленного - UNDECLARED
    SymbolType ResolveType( const CSymbol* symbol );

    // набор методов, возвращающих информацию о данных, связанных с символом,
    // либо nullptr, если символ - UNDECLARED
    const CMethodInfo* TryResolveMethod( const CSymbol* symbol );
    const CVariableInfo* TryResolveVariable( const CSymbol* symbol );
    const CClassInfo* TryResolveClass( const CSymbol* symbol );


private:
    std::vector<std::unique_ptr<CBlockScope>> blocks;
};