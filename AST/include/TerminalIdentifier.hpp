#ifndef MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP
#define MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP

class CTerminalIdentifier {
public:
    CTerminalIdentifier( const char* const _identifier ) : identifier( _identifier ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const char* const identifier;
};

#endif //MINIJAVACOMPILER_TERMINALIDENTIFIER_HPP
