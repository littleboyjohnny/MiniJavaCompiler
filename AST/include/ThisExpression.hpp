#ifndef MINIJAVACOMPILER_THISEXPRESSION_HPP
#define MINIJAVACOMPILER_THISEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class ThisExpression : public IExpression
{
public:
    ThisExpression(){}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
};

#endif //MINIJAVACOMPILER_THISEXPRESSION_HPP
