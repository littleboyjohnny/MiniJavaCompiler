#ifndef MINIJAVACOMPILER_TERMINALCOMMA_HPP
#define MINIJAVACOMPILER_TERMINALCOMMA_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalComma : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALCOMMA_HPP
