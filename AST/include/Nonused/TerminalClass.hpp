#ifndef MINIJAVACOMPILER_TERMINALCLASS_HPP
#define MINIJAVACOMPILER_TERMINALCLASS_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalClass : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALCLASS_HPP
