// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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


