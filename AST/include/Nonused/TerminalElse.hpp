#ifndef MINIJAVACOMPILER_TERMINALELSE_HPP
#define MINIJAVACOMPILER_TERMINALELSE_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalElse : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALELSE_HPP
