#ifndef MINIJAVACOMPILER_PARAMS_HPP
#define MINIJAVACOMPILER_PARAMS_HPP

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

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IParam * const param;
    const IAdditionalParamS * const additionalParamS;
};

#endif //MINIJAVACOMPILER_PARAMS_HPP
