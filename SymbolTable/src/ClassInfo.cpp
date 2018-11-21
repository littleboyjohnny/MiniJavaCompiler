#include <include/ClassInfo.h>
#include <include/Symbol.h>

#include <cassert>


CClassInfo::CClassInfo( const CSymbol *_name ) :
    scope( nullptr )
{
    assert( _name != nullptr );

    name = _name;
    scope = std::make_unique<CBlockScope>();
}

CBlockScope *CClassInfo::GetScope()
{
    assert( scope != nullptr );

    return scope.get();
}
