#include <include/SymbolTable.h>

#include <cassert>


CMethodInfo* CSymbolTable::InMethod( const CSymbol* methodName )
{
    assert( methodName != nullptr );

    CMethodInfo* methodInfo = TryResolveMethod( methodName );
    assert( methodInfo != nullptr );

    PushBlockScope( methodInfo->GetScope() );

    return methodInfo;
}

void CSymbolTable::OutMethod( const CSymbol *methodName )
{
    assert( methodName != nullptr );

    CMethodInfo* methodInfo = TryResolveMethod( methodName );
    assert( methodInfo != nullptr );

    PopBlockScope();
}

CClassInfo* CSymbolTable::InClass( const CSymbol *className )
{
    assert( className != nullptr );

    CClassInfo* classInfo = TryResolveClass( className );
    assert( classInfo != nullptr );

    if( classInfo->GetParent() != nullptr ) {
        InClass( classInfo->GetParent() );
    }

    PushBlockScope( classInfo->GetScope() );

    return classInfo;
}

void CSymbolTable::OutClass( const CSymbol *className )
{
    assert( className != nullptr );

    CClassInfo* classInfo = TryResolveClass( className );
    assert( classInfo != nullptr );

    PopBlockScope();

    if( classInfo->GetParent() != nullptr ) {
        OutClass( classInfo->GetParent() );
    }
}


void CSymbolTable::PushBlockScope( CBlockScope *scope )
{
    assert( scope != nullptr );

    blocks.push_back( scope );
}


CBlockScope* CSymbolTable::PopBlockScope()
{
    assert( !blocks.empty() );

    auto ret = blocks.back();
    blocks.pop_back();
    return ret;
}


void CSymbolTable::AddMethod( const CSymbol *symbol, CMethodInfo *methodInfo )
{
    assert( symbol != nullptr );
    assert( methodInfo != nullptr );

    blocks.back()->AddMethod( symbol, methodInfo );
}


void CSymbolTable::AddVariable( const CSymbol *symbol, CVariableInfo *variableInfo )
{
    assert( symbol != nullptr );
    assert( variableInfo != nullptr );

    blocks.back()->AddVariable( symbol, variableInfo );
}


void CSymbolTable::AddClass( const CSymbol *symbol, CClassInfo *classInfo )
{
    assert( symbol != nullptr );
    assert( classInfo != nullptr );

    blocks.back()->AddClass( symbol, classInfo );
}


bool CSymbolTable::TryAddMethod( const CSymbol *symbol, CMethodInfo *methodInfo )
{
    assert( symbol != nullptr );
    assert( methodInfo != nullptr );

    return blocks.back()->TryAddMethod( symbol, methodInfo );
}


bool CSymbolTable::TryAddVariable( const CSymbol *symbol, CVariableInfo *variableInfo )
{
    assert( symbol != nullptr );
    assert( variableInfo != nullptr );

    return blocks.back()->TryAddVariable( symbol, variableInfo );
}


bool CSymbolTable::TryAddClass( const CSymbol *symbol, CClassInfo *classInfo )
{
    assert( symbol != nullptr );
    assert( classInfo != nullptr );

    return blocks.back()->TryAddClass( symbol, classInfo );
}


INameScope::SymbolType CSymbolTable::ResolveType( const CSymbol *symbol ) const
{
    assert( symbol != nullptr );

    // имя может быть переопределено в дочернем блоке, поэтому ищем до первого совпадения
    SymbolType type = SymbolType::UNDECLARED;
    for( auto it = blocks.rbegin(); it != blocks.rend(); ++it ) {
        type = (*it)->ResolveType( symbol );
        if( type != SymbolType::UNDECLARED ) {
            break;
        }
    }
    return type;
}


CMethodInfo *CSymbolTable::TryResolveMethod( const CSymbol *symbol ) const
{
    assert( symbol != nullptr );

    // имя может быть переопределено в дочернем блоке, поэтому ищем до первого совпадения
    CMethodInfo* methodInfo = nullptr;
    for( auto it = blocks.rbegin(); it != blocks.rend(); ++it ) {
        methodInfo = (*it)->TryResolveMethod( symbol );
        if( methodInfo != nullptr ) {
            break;
        }
    }
    return methodInfo;
}


CVariableInfo *CSymbolTable::TryResolveVariable( const CSymbol *symbol ) const
{
    assert( symbol != nullptr );

    // имя может быть переопределено в дочернем блоке, поэтому ищем до первого совпадения
    CVariableInfo* variableInfo = nullptr;
    for( auto it = blocks.rbegin(); it != blocks.rend(); ++it ) {
        variableInfo = (*it)->TryResolveVariable( symbol );
        if( variableInfo != nullptr ) {
            break;
        }
    }
    return variableInfo;
}


CClassInfo *CSymbolTable::TryResolveClass( const CSymbol *symbol ) const
{
    assert( symbol != nullptr );

    // имя может быть переопределено в дочернем блоке, поэтому ищем до первого совпадения
    CClassInfo* classInfo = nullptr;
    for( auto it = blocks.rbegin(); it != blocks.rend(); ++it ) {
        classInfo = (*it)->TryResolveClass( symbol );
        if( classInfo != nullptr ) {
            break;
        }
    }
    return classInfo;
}
