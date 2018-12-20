// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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


int CVariableInfo::GetSize() const
{
    return 4;
}
