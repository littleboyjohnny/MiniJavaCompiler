#include <include/MethodInfo.h>

#include <cassert>


CMethodInfo::CMethodInfo( const CSymbol* _name, const CSymbol* _retTypeName ) :
    scope( nullptr )
{
    assert( _name != nullptr );
    assert( _retTypeName != nullptr );

    name = _name;
    retTypeName = _retTypeName;
}

CBlockScope *CMethodInfo::GetScope()
{
    assert( scope != nullptr );

    return scope.get();
}

void CMethodInfo::SetScope( CBlockScope *_scope )
{
    assert( _scope != nullptr );

    scope.reset( _scope );
}


