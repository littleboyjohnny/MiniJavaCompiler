#ifndef MINIJAVACOMPILER_TERMINALEXTENDS_HPP
#define MINIJAVACOMPILER_TERMINALEXTENDS_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalExtends : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALEXTENDS_HPP
