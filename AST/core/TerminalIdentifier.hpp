#pragma once

#include "IAcceptable.h"
#include "IVisitor.h"
#include <cstring>

class CTerminalIdentifier : public IAcceptable {
public:
    CTerminalIdentifier( const char* const _identifier , int size ) {
        identifier = new char[size + 1];
        std::memcpy( identifier, _identifier, size * sizeof( char ) );
        identifier[size] = '\0';
    }

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    char* identifier;
};


