#pragma once

#include "../interfaces/IType.h"
#include "../core/IVisitor.h"

class CIntArrayType : public IType {
public:
    CIntArrayType() {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


