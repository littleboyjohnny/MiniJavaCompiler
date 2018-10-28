#ifndef MINIJAVACOMPILER_CUSTOMTYPE_HPP
#define MINIJAVACOMPILER_CUSTOMTYPE_HPP

#include "../interfaces/IType.h"
#include "../interfaces/IVisitor.h"
#include "IdentifierExpression.hpp"

class CCustomType : public IType {
public:
    CCustomType( const CIdentifierExpression * const _typeName ) :
        typeName( _typeName )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const CIdentifierExpression * const typeName;
};

#endif //MINIJAVACOMPILER_CUSTOMTYPE_HPP
