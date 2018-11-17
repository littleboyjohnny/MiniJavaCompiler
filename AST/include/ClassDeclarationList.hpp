#pragma once

#include "../interfaces/IClassDeclarationS.h"
#include "../interfaces/IClassDeclaration.h"
#include "../core/IVisitor.h"

#include <vector>

class CClassDeclarationList : public IClassDeclarationS {
public:
    CClassDeclarationList()
    {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    mutable std::vector<const IClassDeclaration *> children;
};


