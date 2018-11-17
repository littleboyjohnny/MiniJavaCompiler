#pragma once

#include "IAcceptable.h"
#include "IVisitor.h"

class CTerminalIntliteral : public IAcceptable {
public:
    CTerminalIntliteral( const int _intliteral ) : intliteral( _intliteral ) {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const int intliteral;
};


