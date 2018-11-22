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

const CSymbol *CMethodInfo::GetName() const
{
    assert( name != nullptr );

    return name;
}

const CSymbol *CMethodInfo::GetRetTypeName() const
{
    assert( retTypeName != nullptr );

    return retTypeName;
}


std::string CMethodInfo::GetStringRepresentation() const
{
    std::string repr = retTypeName->GetString() + " " + name->GetString() + "(";
    for( auto name : parameters ) {
        repr += scope->TryResolveVariable( name )->GetStringRepresentation() + ", ";
    }
    if( !parameters.empty() ) {
        repr = repr.substr( 0, repr.size() - 2 );
    }
    repr += ")";
    return repr;
}


CBlockScope* CMethodInfo::GetScope()
{
    assert( scope != nullptr );

    return scope.get();
}


const CBlockScope *CMethodInfo::GetScope() const
{
    assert( scope != nullptr );

    return scope.get();
}

const CVariableInfo* CMethodInfo::TryResolveParameter( int paramIndex ) const
{
    assert( paramIndex >= 0 );

    if( paramIndex < parameters.size() ) {
        const CSymbol* paramSymbol = parameters[paramIndex];
        return scope->TryResolveVariable( paramSymbol );
    } else {
        return nullptr;
    }
}

const CVariableInfo* CMethodInfo::TryResolveParameter( const CSymbol* paramSymbol ) const
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

const std::vector<const CSymbol*> &CMethodInfo::GetParameterNames() const
{
    return parameters;
}
