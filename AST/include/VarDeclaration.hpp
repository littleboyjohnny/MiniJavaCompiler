#ifndef MINIJAVACOMPILER_VARDECLARATION_HPP
#define MINIJAVACOMPILER_VARDECLARATION_HPP

#include "../interfaces/IVarDeclaration.h"
#include "../interfaces/IVisitor.h"
#include "../interfaces/IType.h"

#include "../include/TerminalIdentifier.hpp"

class CVarDeclaration : public IVarDeclaration {
public:
    CVarDeclaration( const IType * const _type,
            const CTerminalIdentifier * const _identifier ) :
            type(_type),
            identifier(_identifier)
    {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const IType * const type;
    const CTerminalIdentifier * const identifier;
};

#endif //MINIJAVACOMPILER_VARDECLARATION_HPP
