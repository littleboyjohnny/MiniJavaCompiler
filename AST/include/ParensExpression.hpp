#ifndef MINIJAVACOMPILER_PARENSEXPRESSION_HPP
#define MINIJAVACOMPILER_PARENSEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CParensExpression : public IExpression
{
public:
    CParensExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression* const expression;
};
#endif //MINIJAVACOMPILER_PARENSEXPRESSION_HPP
