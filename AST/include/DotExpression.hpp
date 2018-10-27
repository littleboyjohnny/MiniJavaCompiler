#ifndef MINIJAVACOMPILER_DOTEXPRESSION_HPP
#define MINIJAVACOMPILER_DOTEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class DotExpression : public IExpression
{
public:
    DotExpression( const IExpression* const _expression,
            const IExpression* const _parenExpression ) :
            expression( _expression ),
            parenExpression( _parenExpression )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
    const IExpression* const parenExpression;
};

#endif //MINIJAVACOMPILER_DOTEXPRESSION_HPP
