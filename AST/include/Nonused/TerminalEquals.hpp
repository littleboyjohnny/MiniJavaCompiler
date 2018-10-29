#ifndef MINIJAVACOMPILER_TERMINALEQUALS_HPP
#define MINIJAVACOMPILER_TERMINALEQUALS_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalEquals : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALEQUALS_HPP
