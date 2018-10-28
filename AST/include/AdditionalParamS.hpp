#ifndef MINIJAVACOMPILER_ADDITIONALPARAMS_HPP
#define MINIJAVACOMPILER_ADDITIONALPARAMS_HPP

#include "../interfaces/IAdditionalParamS.h"
#include "../interfaces/IAdditionalParam.h"

class CAdditionalParamS : public IAdditionalParamS {
public:
    CAdditionalParamS( const IAdditionalParamS * const _additionalParamS,
                       const IAdditionalParam * const _additionalParam ) :
        additionalParamS( _additionalParamS ),
        additionalParam( _additionalParam )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IAdditionalParamS * const additionalParamS;
    const IAdditionalParam * const additionalParam;
};

#endif //MINIJAVACOMPILER_ADDITIONALPARAMS_HPP
