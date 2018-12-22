#include <include/VariableInfo.h>

#include <cassert>


CVariableInfo::CVariableInfo( const CSymbol* _name, const CSymbol* _typeName, int _offset )
{
    assert( _name != nullptr );
    assert( _typeName != nullptr );
    assert( offset >= 0 );

    name = _name;
    typeName = _typeName;
    offset = _offset;
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


int CVariableInfo::GetSize() const
{
    return 4;
}
