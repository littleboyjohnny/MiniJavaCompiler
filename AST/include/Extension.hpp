#ifndef MINIJAVACOMPILER_EXTENSION_HPP
#define MINIJAVACOMPILER_EXTENSION_HPP

#include "../interfaces/IExtension.h"
#include "../interfaces/IVisitor.h"

#include "../include/TerminalIdentifier.hpp"

class CExtension : public IExtension {
public:
    CExtension( const CTerminalIdentifier * const _className ) :
            className( _className )
    {}

    void Accept( IVisitor * visitor )
    {
        visitor->Visit( this );
    }

private:
    const CTerminalIdentifier * const className;
};

#endif //MINIJAVACOMPILER_EXTENSION_HPP
