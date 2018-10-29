#ifndef MINIJAVACOMPILER_TERMINALLCURL_HPP
#define MINIJAVACOMPILER_TERMINALLCURL_HPP

#include "../interfaces/IAcceptable.h"
#include "../interfaces/IVisitor.h"

class CTerminalLcurl : public IAcceptable {
public:

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_TERMINALLCURL_HPP
