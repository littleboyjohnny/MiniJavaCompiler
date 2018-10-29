#ifndef MINIJAVACOMPILER_TERMINALSTRING_HPP
#define MINIJAVACOMPILER_TERMINALSTRING_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalString : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALSTRING_HPP
