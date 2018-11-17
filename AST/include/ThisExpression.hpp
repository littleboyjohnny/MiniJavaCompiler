#pragma once

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CThisExpression : public IExpression
{
public:
    CThisExpression(){}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};


