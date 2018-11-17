#pragma once

#include "../interfaces/IExtension.h"
#include "../core/IVisitor.h"

#include "../core/TerminalIdentifier.hpp"

class CExtension : public IExtension {
public:
    CExtension( const CTerminalIdentifier * const _className ) :
            className( _className )
    {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const className;
};


