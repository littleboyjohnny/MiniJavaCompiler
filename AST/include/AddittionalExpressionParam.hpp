#ifndef MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
#define MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP

#include "../interfaces/IAdditionalExpressionParam.h"
#include "../interfaces/IExpression.h"

class AddittionalExpressionParam: public IAdditionalParam
{
public:
    AddittionalExpressionParam( const IExpression* const _expression ) : expression( _expression ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression* const expression;
};
#endif //MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
