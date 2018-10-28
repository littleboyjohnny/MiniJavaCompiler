#ifndef MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
#define MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP

#include "../interfaces/IAdditionalExpressionParamS.h"
#include "../interfaces/IAdditionalExpressionParam.h"
#include "../interfaces/IVisitor.h"

class CAddittionalExpressionParamS : public IAdditionalExpressionParamS
{
public:
    CAddittionalExpressionParamS( const IAdditionalExpressionParamS* const _addittionalExpressionParamS,
            const IAdditionalExpressionParam* const  _addittionalExpressionParam) :
            addittionalExpressionParamS( _addittionalExpressionParamS ),
            addittionalExpressionParam( _addittionalExpressionParam )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IAdditionalExpressionParamS* const addittionalExpressionParamS;
    const IAdditionalExpressionParam* const  addittionalExpressionParam;
};
#endif //MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
