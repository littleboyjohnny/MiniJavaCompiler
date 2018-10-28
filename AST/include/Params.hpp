//
// Created by ivb on 10/28/18.
//

#ifndef MINIJAVACOMPILER_PARAMS_HPP
#define MINIJAVACOMPILER_PARAMS_HPP

#include "../interfaces/IParams.h"
#include "../interfaces/IType.h"
#include "../interfaces/IAdditionalParamS.h"
#include "TerminalIdentifier.hpp"


class CParams : public IParams {
public:
    CParams( const IType * const _type,
             const CTerminalIdentifier * const _identifier,
             const IAdditionalParamS * const _additionalParamS ) :
        type( _type ),
        identifier( _identifier ),
        additionalParamS( _additionalParamS )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IType * const type;
    const CTerminalIdentifier * const identifier;
    const IAdditionalParamS * const additionalParamS;
};

#endif //MINIJAVACOMPILER_PARAMS_HPP
