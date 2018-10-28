#ifndef MINIJAVACOMPILER_BOOLEANTYPE_HPP
#define MINIJAVACOMPILER_BOOLEANTYPE_HPP

#include "../interfaces/IType.h"
#include "../interfaces/IVisitor.h"

class CBooleanType : public IType {
public:
    CBooleanType() {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_BOOLEANTYPE_HPP
