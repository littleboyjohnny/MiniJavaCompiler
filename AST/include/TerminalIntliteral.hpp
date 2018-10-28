#ifndef MINIJAVACOMPILER_TERMINALINTLITERAL_HPP
#define MINIJAVACOMPILER_TERMINALINTLITERAL_HPP

class CTerminalIntliteral {
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
