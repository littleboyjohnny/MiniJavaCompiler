// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

#include "../core/TerminalIntliteral.hpp"

class CIntliteralExpression : public IExpression
{
public:
    CIntliteralExpression( const CTerminalIntliteral* const _intliteral ) : intliteral( _intliteral ) {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const CTerminalIntliteral> intliteral;
};


