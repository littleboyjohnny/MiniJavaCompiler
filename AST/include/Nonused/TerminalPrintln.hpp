#ifndef MINIJAVACOMPILER_TERMINALPRINTLN_HPP
#define MINIJAVACOMPILER_TERMINALPRINTLN_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalPrintln : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALPRINTLN_HPP
