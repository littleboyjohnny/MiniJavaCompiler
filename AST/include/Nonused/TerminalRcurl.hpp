#ifndef MINIJAVACOMPILER_TERMINALRCURL_HPP
#define MINIJAVACOMPILER_TERMINALRCURL_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalRcurl : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALRCURL_HPP
