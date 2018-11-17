#pragma once

#include <memory>

#include "../interfaces/IAdditionalExpressionParam.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAdditionalParam.h"
#include "../core/IVisitor.h"

class CAdditionalExpressionParam: public IAdditionalExpressionParam
{
public:
    CAdditionalExpressionParam( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IExpression> expression;
};

