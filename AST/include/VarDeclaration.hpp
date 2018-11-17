#pragma once

#include "../interfaces/IVarDeclaration.h"
#include "../core/IVisitor.h"
#include "../interfaces/IType.h"

#include "../core/TerminalIdentifier.hpp"

class CVarDeclaration : public IVarDeclaration {
public:
    CVarDeclaration( const IType * const _type,
            const CTerminalIdentifier * const _identifier ) :
            type(_type),
            identifier(_identifier)
    {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const IType * const type;
    const CTerminalIdentifier * const identifier;
};


