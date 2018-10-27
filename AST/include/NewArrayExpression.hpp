#ifndef MINIJAVACOMPILER_ARRAYEXPRESSION_HPP
#define MINIJAVACOMPILER_ARRAYEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class NewArrayExpression : public IExpression
{
public:
    NewArrayExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
};

#endif //MINIJAVACOMPILER_ARRAYEXPRESSION_HPP
