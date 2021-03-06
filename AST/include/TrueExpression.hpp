#pragma once

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CTrueExpression : public IExpression
{
public:
    CTrueExpression(){}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


