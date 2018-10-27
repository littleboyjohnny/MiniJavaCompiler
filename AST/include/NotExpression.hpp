#ifndef MINIJAVACOMPILER_NOTEXPRESSION_HPP
#define MINIJAVACOMPILER_NOTEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class NotExpression : public IExpression
{
public:
    NotExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
};

#endif //MINIJAVACOMPILER_NOTEXPRESSION_HPP
