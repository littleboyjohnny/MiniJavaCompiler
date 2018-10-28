#ifndef MINIJAVACOMPILER_CUSTOMTYPE_HPP
#define MINIJAVACOMPILER_CUSTOMTYPE_HPP

#include "../interfaces/IType.h"
#include "../interfaces/IVisitor.h"
#include "IdentifierExpression.hpp"

class CCustomType : public IType {
public:
    CCustomType( const IdentifierExpression * const _typeName ) :
        typeName( _typeName )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IdentifierExpression * const typeName;
};

#endif //MINIJAVACOMPILER_CUSTOMTYPE_HPP
