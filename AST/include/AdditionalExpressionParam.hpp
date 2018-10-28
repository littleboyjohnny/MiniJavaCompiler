#ifndef MINIJAVACOMPILER_ADDITIONALEXPRESSIONPARAM_HPP
#define MINIJAVACOMPILER_ADDITIONALEXPRESSIONPARAM_HPP

#include "../interfaces/IAdditionalExpressionParam.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAdditionalParam.h"
#include "../interfaces/IVisitor.h"

class CAdditionalExpressionParam: public IAdditionalExpressionParam
{
public:
    CAdditionalExpressionParam( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
};
#endif //MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
