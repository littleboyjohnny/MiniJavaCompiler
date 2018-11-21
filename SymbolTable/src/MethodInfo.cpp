#include <include/MethodInfo.h>

#include <cassert>
#include <algorithm>


CMethodInfo::CMethodInfo( const CSymbol* _name, const CSymbol* _retTypeName ) :
    scope( nullptr )
{
    assert( _name != nullptr );
    assert( _retTypeName != nullptr );

    name = _name;
    retTypeName = _retTypeName;

    scope = std::make_unique<CBlockScope>();
}

CBlockScope* CMethodInfo::GetScope()
{
    assert( scope != nullptr );

    return scope.get();
}

const CVariableInfo* CMethodInfo::TryResolveParameter( int paramIndex )
{
    assert( paramIndex >= 0 );

    if( paramIndex < parameters.size() ) {
        const CSymbol* paramSymbol = parameters[paramIndex];
        return scope->TryResolveVariable( paramSymbol );
    } else {
        return nullptr;
    }
}

const CVariableInfo* CMethodInfo::TryResolveParameter( const CSymbol* paramSymbol )
{
    assert( paramSymbol != nullptr );

    auto it = std::find( std::begin( parameters ), std::end( parameters ), paramSymbol );
    if( it != std::end( parameters ) ) {
        return scope->TryResolveVariable( paramSymbol );
    } else {
        return nullptr;
    }
}

void CMethodInfo::RegisterAsParameter( const CSymbol* symbol )
{
    assert( symbol != nullptr );

    parameters.push_back( symbol );
}

bool CMethodInfo::TryRegisterAsParameter( const CSymbol* symbol )
{
    assert( symbol != nullptr );

    auto it = std::find( std::begin( parameters ), std::end( parameters ), symbol );
    if( it != std::end( parameters ) ) {
        RegisterAsParameter( symbol );
        return true;
    } else {
        return false;
    }
}
