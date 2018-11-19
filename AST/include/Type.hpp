#pragma once

#include <memory>
#include <string>

#include "../interfaces/IType.h"
#include "../core/IVisitor.h"

class CType : public IType {
public:
    CType( const char* const _typeName ) :
            typeName( _typeName )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::string typeName;
};
