#pragma once

#include "Symbol.h"
#include "MethodInfo.hpp"
#include "VariableInfo.hpp"
#include "ClassInfo.hpp"

class INameScope {
public:
    enum SymbolType { UNDECLARED, METHOD, VARIABLE, CLASS };

    // набор методов добавляет переданный символ без каких либо проверок
    virtual void AddMethod( const CSymbol* symbol, const CMethodInfo* methodInfo ) = 0;
    virtual void AddVariable( const CSymbol* symbol, const CVariableInfo* variableInfo ) = 0;
    virtual void AddClass( const CSymbol* symbol, const CClassInfo* classInfo ) = 0;

    // набор методов, проверяющих, что добавляемый символ не создает конфликта имен
    virtual bool TryAddMethod( const CSymbol* symbol, const CMethodInfo* methodInfo ) = 0;
    virtual bool TryAddVariable( const CSymbol* symbol, const CVariableInfo* variableInfo ) = 0;
    virtual bool TryAddClass( const CSymbol* symbol, const CClassInfo* classInfo ) = 0;

    // возвращает тип символа, в т.ч. для еще не добавленного - UNDECLARED
    virtual SymbolType ResolveType( const CSymbol* symbol ) = 0;

    // набор методов, возвращающих информацию о данных, связанных с символом,
    // либо nullptr, если символ - UNDECLARED
    virtual const CMethodInfo* TryResolveMethod( const CSymbol* symbol ) = 0;
    virtual const CVariableInfo* TryResolveVariable( const CSymbol* symbol ) = 0;
    virtual const CClassInfo* TryResolveClass( const CSymbol* symbol ) = 0;
};