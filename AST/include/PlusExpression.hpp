#ifndef MINIJAVACOMPILER_PLUSEXPRESSION_HPP
#define MINIJAVACOMPILER_PLUSEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CPlusExpression : public IExpression
{
public:
    CPlusExpression( const IExpression* const _leftExpression,
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
#endif //MINIJAVACOMPILER_PLUSEXPRESSION_HPP
