#include <include/ClassInfo.h>
#include <include/Symbol.h>

#include <cassert>


CClassInfo::CClassInfo( const CSymbol* _name ) :
    scope( nullptr ),
    parent( nullptr )
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
    std::string S = "class " + name->GetString();
    if( parent != nullptr ) {
        S += " : " + parent->GetString();
    }
    return S;
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

void CClassInfo::SetParent( const CSymbol* _parent )
{
    assert( _parent != nullptr );

    parent = _parent;
}
