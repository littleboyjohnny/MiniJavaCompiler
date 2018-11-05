#ifndef MINIJAVACOMPILER_ARRAYEXPRESSION_HPP
#define MINIJAVACOMPILER_ARRAYEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CNewArrayExpression : public IExpression
{
public:
    CNewArrayExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression* const expression;
};

#endif //MINIJAVACOMPILER_ARRAYEXPRESSION_HPP
