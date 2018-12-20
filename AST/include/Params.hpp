// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IParams.h"
#include "../core/IVisitor.h"
#include "../interfaces/IParam.h"
#include "../interfaces/IAdditionalParamS.h"


class CParams : public IParams {
public:
    CParams( const IParam * const _param,
             const IAdditionalParamS * const _additionalParamS ) :
        param( _param ),
        additionalParamS( _additionalParamS )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IParam > param;
    const std::unique_ptr<const IAdditionalParamS > additionalParamS;
};


