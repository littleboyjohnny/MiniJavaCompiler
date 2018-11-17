#pragma once

#include <memory>

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CLengthExpression : public IExpression
{
public:
    CLengthExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IExpression> expression;
};

