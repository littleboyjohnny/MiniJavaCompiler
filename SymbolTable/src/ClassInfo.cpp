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


const CSymbol* CClassInfo::GetName() const
{
    assert( name != nullptr );

    return name;
}

std::string CClassInfo::GetStringRepresentation() const
{
    return "class " + name->GetString();
}


CBlockScope *CClassInfo::GetScope()
{
    assert( scope != nullptr );

    return scope.get();
}

const CBlockScope *CClassInfo::GetScope() const
{
    assert( scope != nullptr );

    return scope.get();
}
