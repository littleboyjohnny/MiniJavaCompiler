// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IParam.h"
#include "../interfaces/IType.h"
#include "../core/IVisitor.h"
#include "../core/TerminalIdentifier.hpp"

class CParam : public IParam {
public:
    CParam( const IType * const _type, const CTerminalIdentifier * const _identifier ) :
            type( _type ),
            identifier( _identifier )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IType > type;
    const std::unique_ptr<const CTerminalIdentifier > identifier;
};


