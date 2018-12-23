// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "../interfaces/IMethodDeclarationS.h"
#include "../core/IVisitor.h"
#include "../interfaces/IMethodDeclaration.h"

#include <vector>

class CMethodDeclarationList : public IMethodDeclarationS {
public:
    CMethodDeclarationList() {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    mutable std::vector<const IMethodDeclaration *> children;
};


