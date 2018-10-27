#ifndef MINIJAVACOMPILER_FALSEEXPRESSION_HPP
#define MINIJAVACOMPILER_FALSEEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class FalseExpression : public IExpression
{
public:
    FalseExpression(){}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }
private:
};

#endif //MINIJAVACOMPILER_FALSEEXPRESSION_HPP
