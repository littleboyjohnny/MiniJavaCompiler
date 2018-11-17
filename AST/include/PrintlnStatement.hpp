#pragma once

#include "../interfaces/IExpression.h"
#include "../interfaces/IStatement.h"
#include "../core/IVisitor.h"

class CPrintlnStatement : public IStatement {
public:
    CPrintlnStatement( const IExpression * const _expression ) :
        expression( _expression )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression * const expression;
};


