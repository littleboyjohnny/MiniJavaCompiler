#pragma once

#include "../interfaces/IVarDeclarationS.h"
#include "../core/IVisitor.h"
#include "../interfaces/IVarDeclaration.h"

class CVarDeclarationS : public IVarDeclarationS {
public:
    CVarDeclarationS( const IVarDeclarationS * const _varDeclarationS,
            const IVarDeclaration * const _varDeclaration ) :
            varDeclarationS( _varDeclarationS ),
            varDeclaration( _varDeclaration )
    {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const IVarDeclarationS * const varDeclarationS;
    const IVarDeclaration * const varDeclaration;
};


