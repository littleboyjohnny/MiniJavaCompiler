#include <include/ClassInfo.h>
#include <include/Symbol.h>

#include <cassert>


CClassInfo::CClassInfo( const CSymbol *_name )
{
    assert( _name != nullptr );

    name = _name;
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
