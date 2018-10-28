#ifndef MINIJAVACOMPILER_INTARRAYTYPE_HPP
#define MINIJAVACOMPILER_INTARRAYTYPE_HPP

#include "../interfaces/IType.h"
#include "../interfaces/IVisitor.h"

class CIntArrayType : public IType {
public:
    CIntArrayType() {}

    void Accept( const IVisitor* visitor )
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_INTARRAYTYPE_HPP
