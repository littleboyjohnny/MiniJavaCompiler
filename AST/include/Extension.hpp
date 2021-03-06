#pragma once

#include <memory>

#include "../interfaces/IExtension.h"
#include "../core/IVisitor.h"

#include "../core/TerminalIdentifier.hpp"

class CExtension : public IExtension {
public:
    CExtension( const CTerminalIdentifier * const _className ) :
            className( _className )
    {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const CTerminalIdentifier> className;
};


