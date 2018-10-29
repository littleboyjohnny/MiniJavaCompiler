#ifndef MINIJAVACOMPILER_TERMINALMINUS_HPP
#define MINIJAVACOMPILER_TERMINALMINUS_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalMinus : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALMINUS_HPP
