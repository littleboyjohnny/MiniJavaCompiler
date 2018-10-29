#ifndef MINIJAVACOMPILER_TERMINALLPAREN_HPP
#define MINIJAVACOMPILER_TERMINALLPAREN_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalLparen : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALLPAREN_HPP
