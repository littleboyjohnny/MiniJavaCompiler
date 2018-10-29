#ifndef MINIJAVACOMPILER_TERMINALWHILE_HPP
#define MINIJAVACOMPILER_TERMINALWHILE_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalWhile : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALWHILE_HPP
