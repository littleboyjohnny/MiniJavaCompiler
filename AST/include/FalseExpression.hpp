#pragma once

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CFalseExpression : public IExpression
{
public:
    CFalseExpression(){}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


