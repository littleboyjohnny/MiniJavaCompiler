// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>
#include <string>

#include "../interfaces/IType.h"
#include "../core/IVisitor.h"
#include "../core/TerminalIdentifier.hpp"

#include <cassert>
#include <string>

class CType : public IType {
public:
    CType( const char* const _typeName ) :
            typeName( _typeName )
    {}

    CType( const CTerminalIdentifier * const _identifier ) {
        assert( _identifier != nullptr );
        typeName = std::string( _identifier->identifier );
    }

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    std::string GetString() const
    {
        return typeName;
    }

    std::string typeName;
};
