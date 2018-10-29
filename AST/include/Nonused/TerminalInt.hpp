#ifndef MINIJAVACOMPILER_TERMINALINT_HPP
#define MINIJAVACOMPILER_TERMINALINT_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalInt : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALINT_HPP
