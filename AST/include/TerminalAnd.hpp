#ifndef MINIJAVACOMPILER_TERMINALAND_HPP
#define MINIJAVACOMPILER_TERMINALAND_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalAnd : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALAND_HPP
