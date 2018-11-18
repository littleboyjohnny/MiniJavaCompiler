#include <include/VariableInfo.h>

#include <cassert>


CVariableInfo::CVariableInfo( const CSymbol* _name, const CSymbol* _typeName )
{
    assert( _name != nullptr );
    assert( _typeName != nullptr );

    name = _name;
    typeName = _typeName;
}
