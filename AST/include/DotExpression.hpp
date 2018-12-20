// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

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

    const std::unique_ptr<const IExpression> expression;
    const std::unique_ptr<const CTerminalIdentifier> identifier;
    const std::unique_ptr<const IExpressionParamS> expressionParamS;
};


