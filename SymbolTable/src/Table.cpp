#include <include/Table.h>

#include <cassert>


void CTable::AddNewBlockScope()
{
    blocks.push_back( std::make_unique<CBlockScope>( new CBlockScope() ) );
}


void CTable::AddMethod( const CSymbol *symbol, const CMethodInfo *methodInfo )
{
    assert( symbol != nullptr );
    assert( methodInfo != nullptr );

    blocks.back()->AddMethod( symbol, methodInfo );
}


void CTable::AddVariable( const CSymbol *symbol, const CVariableInfo *variableInfo )
{
    assert( symbol != nullptr );
    assert( variableInfo != nullptr );

    blocks.back()->AddVariable( symbol, variableInfo );
}


void CTable::AddClass( const CSymbol *symbol, const CClassInfo *classInfo )
{
    assert( symbol != nullptr );
    assert( classInfo != nullptr );

    blocks.back()->AddClass( symbol, classInfo );
}


bool CTable::TryAddMethod( const CSymbol *symbol, const CMethodInfo *methodInfo )
{
    assert( symbol != nullptr );
    assert( methodInfo != nullptr );

    return blocks.back()->TryAddMethod( symbol, methodInfo );
}


bool CTable::TryAddVariable( const CSymbol *symbol, const CVariableInfo *variableInfo )
{
    assert( symbol != nullptr );
    assert( variableInfo != nullptr );

    return blocks.back()->TryAddVariable( symbol, variableInfo );
}


bool CTable::TryAddClass( const CSymbol *symbol, const CClassInfo *classInfo )
{
    assert( symbol != nullptr );
    assert( classInfo != nullptr );

    return blocks.back()->TryAddClass( symbol, classInfo );
}


INameScope::SymbolType CTable::ResolveType( const CSymbol *symbol )
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


const CMethodInfo *CTable::TryResolveMethod( const CSymbol *symbol )
{
    assert( symbol != nullptr );

    // имя может быть переопределено в дочернем блоке, поэтому ищем до первого совпадения
    const CMethodInfo* methodInfo = nullptr;
    for( auto it = blocks.rbegin(); it != blocks.rend(); ++it ) {
        methodInfo = (*it)->TryResolveMethod( symbol );
        if( methodInfo != nullptr ) {
            break;
        }
    }
    return methodInfo;
}


const CVariableInfo *CTable::TryResolveVariable( const CSymbol *symbol )
{
    assert( symbol != nullptr );

    // имя может быть переопределено в дочернем блоке, поэтому ищем до первого совпадения
    const CVariableInfo* variableInfo = nullptr;
    for( auto it = blocks.rbegin(); it != blocks.rend(); ++it ) {
        variableInfo = (*it)->TryResolveVariable( symbol );
        if( variableInfo != nullptr ) {
            break;
        }
    }
    return variableInfo;
}


const CClassInfo *CTable::TryResolveClass( const CSymbol *symbol )
{
    assert( symbol != nullptr );

    // имя может быть переопределено в дочернем блоке, поэтому ищем до первого совпадения
    const CClassInfo* classInfo = nullptr;
    for( auto it = blocks.rbegin(); it != blocks.rend(); ++it ) {
        classInfo = (*it)->TryResolveClass( symbol );
        if( classInfo != nullptr ) {
            break;
        }
    }
    return classInfo;
}
