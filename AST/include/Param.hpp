#pragma once

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

    const IType * const type;
    const CTerminalIdentifier * const identifier;
};


