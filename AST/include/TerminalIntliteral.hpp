#ifndef MINIJAVACOMPILER_TERMINALINTLITERAL_HPP
#define MINIJAVACOMPILER_TERMINALINTLITERAL_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalIntliteral : public IAcceptable {
public:
    CTerminalIntliteral( const int _intliteral ) : intliteral( _intliteral ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const int intliteral;
};

#endif //MINIJAVACOMPILER_TERMINALINTLITERAL_HPP
