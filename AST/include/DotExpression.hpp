#ifndef MINIJAVACOMPILER_DOTEXPRESSION_HPP
#define MINIJAVACOMPILER_DOTEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IExpressionParamS.h"
#include "../interfaces/IVisitor.h"

#include "../include/TerminalIdentifier.hpp"

class CDotExpression : public IExpression
{
public:
    CDotExpression( const IExpression* const _expression,
            const CTerminalIdentifier * const _identifier,
            const IExpressionParamS* const _expressionParamS ) :
            expression( _expression ),
            identifier( _identifier ),
            expressionParamS( _expressionParamS )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

    const IExpression * const expression;
    const CTerminalIdentifier * const identifier;
    const IExpressionParamS * const expressionParamS;
};

#endif //MINIJAVACOMPILER_DOTEXPRESSION_HPP
