#ifndef MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP
#define MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"
#include <cstring>

class CTerminalIdentifier : public IAcceptable {
public:
    CTerminalIdentifier( const char* const _identifier , int size ) {
        identifier = new char[size + 1];
        std::memcpy( identifier, _identifier, size * sizeof( char ) );
        identifier[size] = '\0';
    }

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    char* identifier;
};

#endif //MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP
