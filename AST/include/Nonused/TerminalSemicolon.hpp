#ifndef MINIJAVACOMPILER_TERMINALSEMICOLON_HPP
#define MINIJAVACOMPILER_TERMINALSEMICOLON_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalSemicolon : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALSEMICOLON_HPP
