#ifndef MINIJAVACOMPILER_EXPRESSIONPARAMS_HPP
#define MINIJAVACOMPILER_EXPRESSIONPARAMS_HPP

#include "../interfaces/IExpressionParamS.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAddittionalExpressionParamS.h"

class ExpressionParamS : public IExpressionParamS
{
public:
    ExpressionParamS( const IExpression* const _expression,
            const IAddittionalExpressionParamS* const _addittionalExpressionParamS) :
            expression(_expression),
            addittionalExpressionParamS(_addittionalExpressionParamS)
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
    const IAddittionalExpressionParamS* const addittionalExpressionParamS;
};
#endif //MINIJAVACOMPILER_EXPRESSIONPARAMS_HPP
