// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <vector>

#include "../interfaces/IVarDeclarationS.h"
#include "../core/IVisitor.h"
#include "../interfaces/IVarDeclaration.h"

class CVarDeclarationList : public IVarDeclarationS {
public:
    CVarDeclarationList()
    {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    mutable std::vector<const IVarDeclaration *> children;
};


