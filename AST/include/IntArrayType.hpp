#pragma once

#include "../interfaces/IType.h"
#include "../core/IVisitor.h"

class CIntArrayType : public IType {
public:
    CIntArrayType() {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


