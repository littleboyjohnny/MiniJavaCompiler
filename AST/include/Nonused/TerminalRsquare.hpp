#ifndef MINIJAVACOMPILER_TERMINALRSQUARE_HPP
#define MINIJAVACOMPILER_TERMINALRSQUARE_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalRsquale : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALRSQUARE_HPP
