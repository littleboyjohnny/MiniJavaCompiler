#pragma once

#include "Symbol.h"

class CMethodInfo;
class CVariableInfo;
class CClassInfo;

class INameScope {
public:
    enum SymbolType { UNDECLARED, METHOD, VARIABLE, CLASS };

    // набор методов добавляет переданный символ без каких либо проверок
    virtual void AddMethod( const CSymbol* symbol, CMethodInfo* methodInfo ) = 0;
    virtual void AddVariable( const CSymbol* symbol, CVariableInfo* variableInfo ) = 0;
    virtual void AddClass( const CSymbol* symbol, CClassInfo* classInfo ) = 0;

    // набор методов, проверяющих, что добавляемый символ не создает конфликта имен
    virtual bool TryAddMethod( const CSymbol* symbol, CMethodInfo* methodInfo ) = 0;
    virtual bool TryAddVariable( const CSymbol* symbol, CVariableInfo* variableInfo ) = 0;
    virtual bool TryAddClass( const CSymbol* symbol, CClassInfo* classInfo ) = 0;

    // возвращает тип символа, в т.ч. для еще не добавленного - UNDECLARED
    virtual SymbolType ResolveType( const CSymbol* symbol ) const = 0;

    // набор методов, возвращающих информацию о данных, связанных с символом,
    // либо nullptr, если символ - UNDECLARED
    virtual const CMethodInfo* TryResolveMethod( const CSymbol* symbol ) const = 0;
    virtual const CVariableInfo* TryResolveVariable( const CSymbol* symbol ) const = 0;
    virtual const CClassInfo* TryResolveClass( const CSymbol* symbol ) const = 0;
};