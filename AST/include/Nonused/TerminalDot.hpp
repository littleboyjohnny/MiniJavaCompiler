#ifndef MINIJAVACOMPILER_TERMINALDOT_HPP
#define MINIJAVACOMPILER_TERMINALDOT_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalDot : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALDOT_HPP
