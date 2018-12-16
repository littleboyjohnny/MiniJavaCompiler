#include <include/ClassInfo.h>
#include <include/Symbol.h>

#include <cassert>


CClassInfo::CClassInfo( const CSymbol* _name ) :
    scope( nullptr ),
    parentName( nullptr ),
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

const CSymbol* CClassInfo::GetParent() const
{
    return parentName;
}

std::string CClassInfo::GetStringRepresentation() const
{
    std::string S = "class " + name->GetString();
    if( parentName != nullptr ) {
        S += " : " + parentName->GetString();
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

void CClassInfo::SetParentName( const CSymbol *_parentName )
{
    assert( _parentName != nullptr );

    parentName = _parentName;
}


void CClassInfo::SetParent( const CClassInfo* _parent )
{
    assert( _parent != nullptr );

    parent = _parent;
}

int CClassInfo::GetSize() const
{
    int totalSize = 0;

    for( auto varName : scope->GetVariableNames() ) {
        CVariableInfo* varInfo = scope->TryResolveVariable( varName );
        assert( varInfo != nullptr );
        totalSize += varInfo->GetSize();
    }

    for( auto className : scope->GetClassNames() ) {
        CClassInfo* classInfo = scope->TryResolveClass( className );
        assert( classInfo != nullptr );
        totalSize += classInfo->GetSize();
    }

    if( parent != nullptr ) {
        totalSize += parent->GetSize();
    }

    return totalSize;
}
