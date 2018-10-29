#ifndef MINIJAVACOMPILER_TERMINLRPAREN_HPP
#define MINIJAVACOMPILER_TERMINLRPAREN_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalRparen : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINLRPAREN_HPP
