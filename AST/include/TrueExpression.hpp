#ifndef MINIJAVACOMPILER_TRUEEXPRESSION_HPP
#define MINIJAVACOMPILER_TRUEEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CTrueExpression : public IExpression
{
public:
    CTrueExpression(){}

    void Accept( const IVisitor* visitor )
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TRUEEXPRESSION_HPP
