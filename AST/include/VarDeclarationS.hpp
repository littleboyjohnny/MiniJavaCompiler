// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

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

    const std::unique_ptr<const IVarDeclarationS> varDeclarationS;
    const std::unique_ptr<const IVarDeclaration> varDeclaration;
};


