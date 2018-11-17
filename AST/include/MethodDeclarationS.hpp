#pragma once

#include <memory>

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

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IMethodDeclarationS > methodDeclarationS;
    const std::unique_ptr<const IMethodDeclaration > methodDeclaration;
};


