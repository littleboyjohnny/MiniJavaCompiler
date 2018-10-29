#ifndef MINIJAVACOMPILER_TERMINALTHIS_HPP
#define MINIJAVACOMPILER_TERMINALTHIS_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalThis : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALTHIS_HPP
