#ifndef MINIJAVACOMPILER_TERMINALINTLITERAL_HPP
#define MINIJAVACOMPILER_TERMINALINTLITERAL_HPP

#include "IAcceptable.h"
#include "IVisitor.h"

class CTerminalIntliteral : public IAcceptable {
public:
    CTerminalIntliteral( const int _intliteral ) : intliteral( _intliteral ) {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const int intliteral;
};

#endif //MINIJAVACOMPILER_TERMINALINTLITERAL_HPP
