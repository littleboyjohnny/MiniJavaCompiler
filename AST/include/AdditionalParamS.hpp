// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IAdditionalParamS.h"
#include "../interfaces/IAdditionalParam.h"
#include "../core/IVisitor.h"

class CAdditionalParamS : public IAdditionalParamS {
public:
    CAdditionalParamS( const IAdditionalParamS * const _additionalParamS,
                       const IAdditionalParam * const _additionalParam ) :
        additionalParamS( _additionalParamS ),
        additionalParam( _additionalParam )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IAdditionalParamS> additionalParamS;
    const std::unique_ptr<const IAdditionalParam> additionalParam;
};


