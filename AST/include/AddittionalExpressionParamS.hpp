#ifndef MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
#define MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP

#include "../interfaces/IAddittionalExpressionParamS.h"
#include "../interfaces/IAddittionalExpressionParam.h"

class AddittionalExpressionParamS : public IAdditionalParamS
{
public:
    AddittionalExpressionParamS( const IAddittionalExpressionParamS* const _addittionalExpressionParamS,
            const IAddittionalExpressionParam* const  _addittionalExpressionParam) :
            addittionalExpressionParamS( _addittionalExpressionParamS ),
            addittionalExpressionParam( _addittionalExpressionParam )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IAddittionalExpressionParamS* const addittionalExpressionParamS;
    const IAddittionalExpressionParam* const  addittionalExpressionParam;
};
#endif //MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
