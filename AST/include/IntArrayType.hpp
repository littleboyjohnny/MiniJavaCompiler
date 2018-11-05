#ifndef MINIJAVACOMPILER_INTARRAYTYPE_HPP
#define MINIJAVACOMPILER_INTARRAYTYPE_HPP

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

#endif //MINIJAVACOMPILER_INTARRAYTYPE_HPP
