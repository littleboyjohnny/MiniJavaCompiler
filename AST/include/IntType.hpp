#ifndef MINIJAVACOMPILER_INTTYPE_HPP
#define MINIJAVACOMPILER_INTTYPE_HPP

#include "../interfaces/IType.h"
#include "../interfaces/IVisitor.h"

class CIntType : public IType {
public:
    CIntType() {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_INTTYPE_HPP
