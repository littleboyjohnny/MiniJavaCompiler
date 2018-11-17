#pragma once

#include "../interfaces/IMethodDeclarationS.h"
#include "../core/IVisitor.h"
#include "../interfaces/IMethodDeclaration.h"

#include <vector>

class CMethodDeclarationList : public IMethodDeclarationS {
public:
    CMethodDeclarationList() {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    mutable std::vector<const IMethodDeclaration *> children;
};


