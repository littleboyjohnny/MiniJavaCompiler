#ifndef MINIJAVACOMPILER_TERMINALTRUE_HPP
#define MINIJAVACOMPILER_TERMINALTRUE_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalTrue : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALTRUE_HPP
