#pragma once

#include "../interfaces/IClassDeclarationS.h"
#include "../interfaces/IClassDeclaration.h"
#include "../core/IVisitor.h"

class CClassDeclarationS : public IClassDeclarationS {
public:
    CClassDeclarationS( const IClassDeclarationS * const _classDeclarationS,
            const IClassDeclaration * const _classDeclaration ) :
            classDeclarationS( _classDeclarationS ),
            classDeclaration( _classDeclaration )
    {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const IClassDeclarationS * const classDeclarationS;
    const IClassDeclaration * const classDeclaration;
};


