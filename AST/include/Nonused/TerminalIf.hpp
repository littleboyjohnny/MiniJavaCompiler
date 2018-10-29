#ifndef MINIJAVACOMPILER_TERMINALIF_HPP
#define MINIJAVACOMPILER_TERMINALIF_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalIf : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALIF_HPP
