// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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


