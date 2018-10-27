#ifndef MINIJAVACOMPILER_LENGTHEXPRESSION_HPP
#define MINIJAVACOMPILER_LENGTHEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class LengthExpression : public IExpression
{
public:
    LengthExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
};
#endif //MINIJAVACOMPILER_LENGTHEXPRESSION_HPP
