#ifndef MINIJAVACOMPILER_EXPRESSIONPARAMS_HPP
#define MINIJAVACOMPILER_EXPRESSIONPARAMS_HPP

#include "../interfaces/IExpressionParamS.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAdditionalExpressionParamS.h"
#include "../interfaces/IVisitor.h"

class CExpressionParamS : public IExpressionParamS
{
public:
    CExpressionParamS( const IExpression* const _expression,
            const IAdditionalExpressionParamS* const _addittionalExpressionParamS) :
            expression(_expression),
            addittionalExpressionParamS(_addittionalExpressionParamS)
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
    const IAdditionalExpressionParamS* const addittionalExpressionParamS;
};
#endif //MINIJAVACOMPILER_EXPRESSIONPARAMS_HPP
