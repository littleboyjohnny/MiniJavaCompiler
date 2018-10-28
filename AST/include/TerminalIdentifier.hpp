#ifndef MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP
#define MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalIdentifier : public IAcceptable {
public:
    CTerminalIdentifier( const char* const _identifier ) : identifier( _identifier ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const char* const identifier;
};

#endif //MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP
