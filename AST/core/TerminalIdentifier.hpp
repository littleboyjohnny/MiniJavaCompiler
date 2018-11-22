#pragma once

#include "IAcceptable.h"
#include "IVisitor.h"
#include <cstring>
#include <cctype>

class CTerminalIdentifier : public IAcceptable {
public:
    CTerminalIdentifier( const char* const _identifier , int size ) {
        while( size > 0 && isspace( _identifier[size - 1] ) ) {
            --size;
        }
        identifier = new char[size + 1];
        std::memcpy( identifier, _identifier, size * sizeof( char ) );
        identifier[size] = '\0';
    }

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    ~CTerminalIdentifier() {
        delete identifier;
    }

    char* identifier;
};


