#ifndef MINIJAVACOMPILER_TRUEEXPRESSION_HPP
#define MINIJAVACOMPILER_TRUEEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CTrueExpression : public IExpression
{
public:
    CTrueExpression(){}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TRUEEXPRESSION_HPP
