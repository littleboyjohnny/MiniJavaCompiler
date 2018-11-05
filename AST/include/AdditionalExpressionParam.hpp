#ifndef MINIJAVACOMPILER_ADDITIONALEXPRESSIONPARAM_HPP
#define MINIJAVACOMPILER_ADDITIONALEXPRESSIONPARAM_HPP

#include "../interfaces/IAdditionalExpressionParam.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IAdditionalParam.h"
#include "../core/IVisitor.h"

class CAdditionalExpressionParam: public IAdditionalExpressionParam
{
public:
    CAdditionalExpressionParam( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression* const expression;
};
#endif //MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
