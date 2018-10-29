#ifndef MINIJAVACOMPILER_TERMINALPUBLIC_HPP
#define MINIJAVACOMPILER_TERMINALPUBLIC_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalPublic : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALPUBLIC_HPP
