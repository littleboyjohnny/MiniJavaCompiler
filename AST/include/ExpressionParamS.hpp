#pragma once

#include <memory>

#include "../interfaces/IExpressionParamS.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAdditionalExpressionParamS.h"
#include "../core/IVisitor.h"

class CExpressionParamS : public IExpressionParamS
{
public:
    CExpressionParamS( const IExpression* const _expression,
            const IAdditionalExpressionParamS* const _addittionalExpressionParamS) :
            expression(_expression),
            addittionalExpressionParamS(_addittionalExpressionParamS)
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IExpression> expression;
    const std::unique_ptr<const IAdditionalExpressionParamS> addittionalExpressionParamS;
};

