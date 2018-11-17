#pragma once

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

#include "../core/TerminalIdentifier.hpp"

class CIdentifierExpression : public IExpression
{
public:
    CIdentifierExpression( const CTerminalIdentifier * const _identifier ) : identifier( _identifier ) {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const identifier;
};


