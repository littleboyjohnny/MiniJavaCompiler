#ifndef MINIJAVACOMPILER_TERMINALVOID_HPP
#define MINIJAVACOMPILER_TERMINALVOID_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalVoid : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALVOID_HPP
