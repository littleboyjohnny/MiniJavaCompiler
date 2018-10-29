#ifndef MINIJAVACOMPILER_TERMINALMAIN_HPP
#define MINIJAVACOMPILER_TERMINALMAIN_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalMain : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALMAIN_HPP
