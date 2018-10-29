#ifndef MINIJAVACOMPILER_TERMINALSTATIC_HPP
#define MINIJAVACOMPILER_TERMINALSTATIC_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalStatic : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALSTATIC_HPP
