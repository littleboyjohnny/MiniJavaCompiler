#ifndef MINIJAVACOMPILER_SQUAREBRACKETSEXPRESSION_HPP
#define MINIJAVACOMPILER_SQUAREBRACKETSEXPRESSION_HPP

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

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression* const expression;
    const IExpression* const squarebraketsExpression;
};

#endif //MINIJAVACOMPILER_SQUAREBRACKETSEXPRESSION_HPP
