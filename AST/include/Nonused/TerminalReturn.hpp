#ifndef MINIJAVACOMPILER_TERMINALRETURN_HPP
#define MINIJAVACOMPILER_TERMINALRETURN_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalReturn : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALRETURN_HPP
