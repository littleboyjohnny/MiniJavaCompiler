#ifndef MINIJAVACOMPILER_MINUSEXPRESSION_HPP
#define MINIJAVACOMPILER_MINUSEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class MinusExpression : public IExpression
{
public:
    MinusExpression( const IExpression* const _leftExpression,
                     const IExpression* const _rightExpression ) :
            leftExpression( _leftExpression ),
            rightExpression( _rightExpression )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const leftExpression;
    const IExpression* const rightExpression;
};
#endif //MINIJAVACOMPILER_MINUSEXPRESSION_HPP
