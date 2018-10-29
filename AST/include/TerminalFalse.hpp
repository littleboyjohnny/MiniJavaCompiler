#ifndef MINIJAVACOMPILER_TERMINALFALSE_HPP
#define MINIJAVACOMPILER_TERMINALFALSE_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalFalse : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALFALSE_HPP
