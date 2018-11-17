#pragma once

#include "../interfaces/IExpression.h"
#include "../interfaces/IExpressionParamS.h"
#include "../core/IVisitor.h"

#include "../core/TerminalIdentifier.hpp"

class CCallExpression : public IExpression
{
public:
    CCallExpression( const IExpression* const _expression,
            const CTerminalIdentifier * const _identifier,
            const IExpressionParamS* const _expressionParamS ) :
            expression( _expression ),
            identifier( _identifier ),
            expressionParamS( _expressionParamS )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression * const expression;
    const CTerminalIdentifier * const identifier;
    const IExpressionParamS * const expressionParamS;
};


