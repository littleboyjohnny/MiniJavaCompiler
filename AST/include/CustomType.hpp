#ifndef MINIJAVACOMPILER_CUSTOMTYPE_HPP
#define MINIJAVACOMPILER_CUSTOMTYPE_HPP

#include "../interfaces/IType.h"
#include "../core/IVisitor.h"
#include "../core/TerminalIdentifier.hpp"

class CCustomType : public IType {
public:
    CCustomType( const CTerminalIdentifier * const _typeName ) :
        typeName( _typeName )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const typeName;
};

#endif //MINIJAVACOMPILER_CUSTOMTYPE_HPP
