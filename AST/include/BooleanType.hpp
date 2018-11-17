#pragma once

#include "../interfaces/IType.h"
#include "../core/IVisitor.h"

class CBooleanType : public IType {
public:
    CBooleanType() {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


