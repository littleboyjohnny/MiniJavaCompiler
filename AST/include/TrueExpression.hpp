#ifndef MINIJAVACOMPILER_TRUEEXPRESSION_HPP
#define MINIJAVACOMPILER_TRUEEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class TrueExpression : public IExpression
{
public:
    TrueExpression(){}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
};

#endif //MINIJAVACOMPILER_TRUEEXPRESSION_HPP
