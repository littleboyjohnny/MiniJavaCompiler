#ifndef MINIJAVACOMPILER_TERMINALPLUS_HPP
#define MINIJAVACOMPILER_TERMINALPLUS_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalPlus : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALPLUS_HPP
