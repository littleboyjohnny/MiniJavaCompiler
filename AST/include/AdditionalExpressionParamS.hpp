#pragma once

#include <memory>

#include "../interfaces/IAdditionalExpressionParamS.h"
#include "../interfaces/IAdditionalExpressionParam.h"
#include "../core/IVisitor.h"

class CAdditionalExpressionParamS : public IAdditionalExpressionParamS
{
public:
    CAdditionalExpressionParamS( const IAdditionalExpressionParamS* const _additionalExpressionParamS,
            const IAdditionalExpressionParam* const  _additionalExpressionParam) :
            additionalExpressionParamS( _additionalExpressionParamS ),
            additionalExpressionParam( _additionalExpressionParam )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IAdditionalExpressionParamS> additionalExpressionParamS;
    const std::unique_ptr<const IAdditionalExpressionParam>  additionalExpressionParam;
};

