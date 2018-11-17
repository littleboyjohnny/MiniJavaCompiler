#pragma once

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CNotExpression : public IExpression
{
public:
    CNotExpression( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression* const expression;
};


