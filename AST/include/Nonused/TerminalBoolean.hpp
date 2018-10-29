#ifndef MINIJAVACOMPILER_TERMINALBOOLEAN_HPP
#define MINIJAVACOMPILER_TERMINALBOOLEAN_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalBoolean : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALBOOLEAN_HPP
