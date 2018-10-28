#ifndef MINIJAVACOMPILER_ANDEXPRESSION_HPP
#define MINIJAVACOMPILER_ANDEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CAndExpression : public IExpression
{
public:
    CAndExpression( const IExpression* const _leftExpression,
                     const IExpression* const _rightExpression ) :
            leftExpression( _leftExpression ),
            rightExpression( _rightExpression )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

    const IExpression* const leftExpression;
    const IExpression* const rightExpression;
};

#endif //MINIJAVACOMPILER_ANDEXPRESSION_HPP
