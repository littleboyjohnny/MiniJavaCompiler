#pragma once

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

    const IExpression* const expression;
    const IExpression* const squarebraketsExpression;
};


