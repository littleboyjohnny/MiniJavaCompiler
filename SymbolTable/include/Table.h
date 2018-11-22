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

    // добавляет блок в области видимости
    void PushBlockScope( CBlockScope *scope );

    // извлекает последний блок видимости
    CBlockScope* PopBlockScope();

    // набор методов добавляет переданный символ без каких либо проверок
    void AddMethod( const CSymbol* symbol, CMethodInfo* methodInfo );
    void AddVariable( const CSymbol* symbol, CVariableInfo* variableInfo );
    void AddClass( const CSymbol* symbol, CClassInfo* classInfo );

    // набор методов, проверяющих, что добавляемый символ не создает конфликта имен
    bool TryAddMethod( const CSymbol* symbol, CMethodInfo* methodInfo );
    bool TryAddVariable( const CSymbol* symbol, CVariableInfo* variableInfo );
    bool TryAddClass( const CSymbol* symbol, CClassInfo* classInfo );

    // возвращает тип символа, в т.ч. для еще не добавленного - UNDECLARED
    SymbolType ResolveType( const CSymbol* symbol ) const;

    // набор методов, возвращающих информацию о данных, связанных с символом,
    // либо nullptr, если символ - UNDECLARED
    const CMethodInfo* TryResolveMethod( const CSymbol* symbol ) const;
    const CVariableInfo* TryResolveVariable( const CSymbol* symbol ) const;
    const CClassInfo* TryResolveClass( const CSymbol* symbol ) const;


private:
    std::vector<CBlockScope*> blocks;
};