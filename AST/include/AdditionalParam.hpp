#pragma once

#include <memory>

#include "../interfaces/IAdditionalParam.h"
#include "../interfaces/IParam.h"
#include "../core/IVisitor.h"

class CAdditionalParam : public IAdditionalParam {
public:
    CAdditionalParam( const IParam * const _param ) :
        param( _param )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IParam> param;
};


