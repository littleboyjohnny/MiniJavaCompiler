#ifndef MINIJAVACOMPILER_TERMINALMULTIPLY_HPP
#define MINIJAVACOMPILER_TERMINALMULTIPLY_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalMultiply : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALMULTIPLY_HPP
