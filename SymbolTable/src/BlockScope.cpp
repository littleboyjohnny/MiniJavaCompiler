#include <include/BlockScope.h>

#include <algorithm>
#include <cassert>


void CBlockScope::AddMethod( const CSymbol* symbol, const CMethodInfo *methodInfo )
{
    assert( symbol != nullptr );
    assert( methodInfo != nullptr );

    methods.insert( { symbol, methodInfo } );
}


void CBlockScope::AddVariable( const CSymbol* symbol, const CVariableInfo *variableInfo )
{
    assert( symbol != nullptr );
    assert( variableInfo != nullptr );

    variables.insert( { symbol, variableInfo } );
}


void CBlockScope::AddClass( const CSymbol* symbol, const CClassInfo *classInfo )
{
    assert( symbol != nullptr );
    assert( classInfo != nullptr );

    classes.insert( { symbol, classInfo } );
}


bool CBlockScope::TryAddMethod( const CSymbol *symbol, const CMethodInfo *methodInfo )
{
    assert( symbol != nullptr );
    assert( methodInfo != nullptr );

    if( ResolveType( symbol ) == SymbolType::UNDECLARED ) {
        AddMethod( symbol, methodInfo );
        return true;
    } else {
        return false;
    }
}


bool CBlockScope::TryAddVariable( const CSymbol *symbol, const CVariableInfo *variableInfo )
{
    assert( symbol != nullptr );
    assert( variableInfo != nullptr );

    if( ResolveType( symbol ) == SymbolType::UNDECLARED ) {
        AddVariable( symbol, variableInfo );
        return true;
    } else {
        return false;
    }
}


bool CBlockScope::TryAddClass( const CSymbol *symbol, const CClassInfo *classInfo )
{
    assert( symbol != nullptr );
    assert( classInfo != nullptr );

    if( ResolveType( symbol ) == SymbolType::UNDECLARED ) {
        AddClass( symbol, classInfo );
        return true;
    } else {
        return false;
    }
}


CBlockScope::SymbolType CBlockScope::ResolveType( const CSymbol* symbol )
{
    assert( symbol != nullptr );

    auto methodIt = methods.find( symbol );
    auto variableIt = variables.find( symbol );
    auto classIt = classes.find( symbol );

    // имя должно быть доступно не более чем в одном множестве
    assert( ( methodIt != methods.end() )
            + ( variableIt != variables.end() )
            + ( classIt != classes.end() ) <= 1 );

    if( methodIt != methods.end() ) {
        return SymbolType::METHOD;
    }

    if( variableIt != variables.end() ) {
        return SymbolType::VARIABLE;
    }

    if( classIt != classes.end() ) {
        return SymbolType::CLASS;
    }

    return SymbolType::UNDECLARED;
}


const CMethodInfo *CBlockScope::TryResolveMethod( const CSymbol* symbol )
{
    assert( symbol != nullptr );

    auto it = methods.find( symbol );
    return it != methods.end() ? it->second : nullptr;
}


const CVariableInfo *CBlockScope::TryResolveVariable( const CSymbol* symbol )
{
    assert( symbol != nullptr );

    auto it = variables.find( symbol );
    return it != variables.end() ? it->second : nullptr;
}


const CClassInfo *CBlockScope::TryResolveClass( const CSymbol* symbol )
{
    assert( symbol != nullptr );

    auto it = classes.find( symbol );
    return it != classes.end() ? it->second : nullptr;
}
