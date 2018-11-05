#ifndef MINIJAVACOMPILER_ADDITIONALEXPRESSIONPARAMS_HPP
#define MINIJAVACOMPILER_ADDITIONALEXPRESSIONPARAMS_HPP

#include "../interfaces/IAdditionalExpressionParamS.h"
#include "../interfaces/IAdditionalExpressionParam.h"
#include "../core/IVisitor.h"

class CAdditionalExpressionParamS : public IAdditionalExpressionParamS
{
public:
    CAdditionalExpressionParamS( const IAdditionalExpressionParamS* const _additionalExpressionParamS,
            const IAdditionalExpressionParam* const  _additionalExpressionParam) :
            additionalExpressionParamS( _additionalExpressionParamS ),
            additionalExpressionParam( _additionalExpressionParam )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IAdditionalExpressionParamS* const additionalExpressionParamS;
    const IAdditionalExpressionParam* const  additionalExpressionParam;
};
#endif //MINIJAVACOMPILER_ADDITTIONALEXPRESSIONPARAM_HPP
