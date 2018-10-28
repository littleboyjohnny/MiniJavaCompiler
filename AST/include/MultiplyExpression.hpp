#ifndef MINIJAVACOMPILER_MULTIPLYEXPRESSION_HPP
#define MINIJAVACOMPILER_MULTIPLYEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CMultiplyExpression : public IExpression
{
public:
    CMultiplyExpression( const IExpression* const _leftExpression,
                        const IExpression* const _rightExpression ) :
            leftExpression( _leftExpression ),
            rightExpression( _rightExpression )
    {}

    void Accept( const IVisitor* visitor )
    {
        visitor->Visit( this );
    }

    const IExpression* const leftExpression;
    const IExpression* const rightExpression;
};
#endif //MINIJAVACOMPILER_MULTIPLYEXPRESSION_HPP
