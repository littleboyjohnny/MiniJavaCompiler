#pragma once

#include "../interfaces/IParams.h"
#include "../core/IVisitor.h"
#include "../interfaces/IParam.h"
#include "../interfaces/IAdditionalParamS.h"


class CParams : public IParams {
public:
    CParams( const IParam * const _param,
             const IAdditionalParamS * const _additionalParamS ) :
        param( _param ),
        additionalParamS( _additionalParamS )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IParam * const param;
    const IAdditionalParamS * const additionalParamS;
};


