#ifndef MINIJAVACOMPILER_SQUAREBRACKETSEXPRESSION_HPP
#define MINIJAVACOMPILER_SQUAREBRACKETSEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class SquarebracketsExpression : public IExpression
{
public:
    SquarebracketsExpression( const IExpression* const _expression,
                              const IExpression* const _squarebraketsExpression) :
                              expression( _expression ),
                              squarebraketsExpression( _squarebraketsExpression )
                              {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
    const IExpression* const squarebraketsExpression;
};

#endif //MINIJAVACOMPILER_SQUAREBRACKETSEXPRESSION_HPP
