#ifndef MINIJAVACOMPILER_ADDITIONALPARAM_HPP
#define MINIJAVACOMPILER_ADDITIONALPARAM_HPP

#include "../interfaces/IAdditionalParam.h"
#include "../interfaces/IParam.h"
#include "../interfaces/IVisitor.h"

class CAdditionalParam : public IAdditionalParam {
public:
    CAdditionalParam( const IParam * const _param ) :
        param( _param )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IParam * const param;
};

#endif //MINIJAVACOMPILER_ADDITIONALPARAM_HPP
