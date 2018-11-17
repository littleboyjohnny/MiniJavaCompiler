#pragma once

#include "../interfaces/IType.h"
#include "../core/IVisitor.h"

class CIntType : public IType {
public:
    CIntType() {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


