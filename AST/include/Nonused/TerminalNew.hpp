#ifndef MINIJAVACOMPILER_TERMINALNEW_HPP
#define MINIJAVACOMPILER_TERMINALNEW_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalNew : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALNEW_HPP
