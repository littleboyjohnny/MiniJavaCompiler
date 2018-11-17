#pragma once

#include "../interfaces/IAdditionalParamS.h"
#include "../interfaces/IAdditionalParam.h"
#include "../core/IVisitor.h"

class CAdditionalParamS : public IAdditionalParamS {
public:
    CAdditionalParamS( const IAdditionalParamS * const _additionalParamS,
                       const IAdditionalParam * const _additionalParam ) :
        additionalParamS( _additionalParamS ),
        additionalParam( _additionalParam )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IAdditionalParamS * const additionalParamS;
    const IAdditionalParam * const additionalParam;
};


