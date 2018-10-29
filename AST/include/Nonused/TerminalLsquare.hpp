#ifndef MINIJAVACOMPILER_TERMINALLSQUARE_HPP
#define MINIJAVACOMPILER_TERMINALLSQUARE_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalLsquare : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALLSQUARE_HPP
