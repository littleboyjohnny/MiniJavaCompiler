#pragma once

#include "../interfaces/IMethodDeclarationS.h"
#include "../core/IVisitor.h"
#include "../interfaces/IMethodDeclaration.h"

class CMethodDeclarationS : public IMethodDeclarationS {
public:
    CMethodDeclarationS( const IMethodDeclarationS * const _methodDeclarationS,
            const IMethodDeclaration * const _methodDeclaration ) :
            methodDeclarationS( _methodDeclarationS ),
            methodDeclaration( _methodDeclaration )
    {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const IMethodDeclarationS * const methodDeclarationS;
    const IMethodDeclaration * const methodDeclaration;
};


