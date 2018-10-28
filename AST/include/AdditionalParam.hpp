#ifndef MINIJAVACOMPILER_ADDITIONALPARAM_HPP
#define MINIJAVACOMPILER_ADDITIONALPARAM_HPP

#include "../interfaces/IAdditionalParam.h"
#include "../interfaces/IType.h"
#include "IdentifierExpression.hpp"

class CAdditionalParam : public IAdditionalParam {
public:
    CAdditionalParam( const IType * const _type, const IdentifierExpression * const _identifier ) :
        type( _type ),
        indentifier( _identifier )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IType * const type;
    const IdentifierExpression * const identifier;
};

#endif //MINIJAVACOMPILER_ADDITIONALPARAM_HPP
