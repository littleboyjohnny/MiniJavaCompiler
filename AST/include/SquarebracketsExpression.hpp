#pragma once

#include <memory>

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CSquarebracketsExpression : public IExpression
{
public:
    CSquarebracketsExpression( const IExpression* const _expression,
                              const IExpression* const _squarebraketsExpression) :
                              expression( _expression ),
                              squarebraketsExpression( _squarebraketsExpression )
                              {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IExpression> expression;
    const std::unique_ptr<const IExpression> squarebraketsExpression;
};


