#ifndef MINIJAVACOMPILER_TERMINALLESS_HPP
#define MINIJAVACOMPILER_TERMINALLESS_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalLess : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALLESS_HPP
