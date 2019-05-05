// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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


