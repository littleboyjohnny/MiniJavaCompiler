//
// Created by ivb on 10/28/18.
//

#ifndef MINIJAVACOMPILER_PARAMS_HPP
#define MINIJAVACOMPILER_PARAMS_HPP

#include "../interfaces/IParams.h"
#include "../interfaces/IType.h"
#include "IdentifierExpression.hpp"
#include "../interfaces/IAdditionalParamS.h"

class CParams : public IParams {
public:
    CParams( const IType * const _type,
             const CIdentifierExpression * const _identifier,
             const IAdditionalParamS * const _additionalParamS ) :
        type( _type ),
        identifier( _identifier ),
        additionalParamS( _additionalParamS )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IType * const type;
    const CIdentifierExpression * const identifier;
    const IAdditionalParamS * const additionalParamS;
};

#endif //MINIJAVACOMPILER_PARAMS_HPP