#pragma once

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

    const IExpression* const expression;
    const IAdditionalExpressionParamS* const addittionalExpressionParamS;
};

