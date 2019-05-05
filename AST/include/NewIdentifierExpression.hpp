// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"
#include "../core/TerminalIdentifier.hpp"

class CNewIdentifierExpression : public IExpression
{
public:
    CNewIdentifierExpression( const CTerminalIdentifier* const _identifier ) : identifier( _identifier ) {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const CTerminalIdentifier> identifier;
};


