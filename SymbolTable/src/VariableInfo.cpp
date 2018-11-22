#include <include/VariableInfo.h>

#include <cassert>


CVariableInfo::CVariableInfo( const CSymbol* _name, const CSymbol* _typeName )
{
    assert( _name != nullptr );
    assert( _typeName != nullptr );

    name = _name;
    typeName = _typeName;
}


const CSymbol* CVariableInfo::GetName() const
{
    return name;
}


const CSymbol* CVariableInfo::GetTypeName() const
{
    return typeName;
}


std::string CVariableInfo::GetStringRepresentation() const
{
    return typeName->GetString() + " " + name->GetString();
}