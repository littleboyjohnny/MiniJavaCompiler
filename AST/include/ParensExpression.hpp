#ifndef MINIJAVACOMPILER_PARENSEXPRESSION_HPP
#define MINIJAVACOMPILER_PARENSEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CParensExpression : public IExpression
{
public:
    CParensExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
};
#endif //MINIJAVACOMPILER_PARENSEXPRESSION_HPP