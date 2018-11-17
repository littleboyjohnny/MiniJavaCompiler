#pragma once

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CNewArrayExpression : public IExpression
{
public:
    CNewArrayExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression* const expression;
};


