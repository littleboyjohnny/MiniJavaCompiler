#ifndef MINIJAVACOMPILER_TERMINALNOT_HPP
#define MINIJAVACOMPILER_TERMINALNOT_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalNot : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALNOT_HPP
