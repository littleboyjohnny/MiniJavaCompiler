// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IClassDeclaration.h"
#include "../core/IVisitor.h"
#include "../interfaces/IExtension.h"
#include "../interfaces/IVarDeclarationS.h"
#include "../interfaces/IMethodDeclarationS.h"

#include "../core/TerminalIdentifier.hpp"

class CClassDeclaration : public IClassDeclaration {
public:
    CClassDeclaration( const CTerminalIdentifier * const _className,
            const IExtension * const _extension,
            const IVarDeclarationS * const _varDeclarationS,
            const IMethodDeclarationS * const _methodDeclarationS ) :
            className( _className ),
            extension( _extension ),
            varDeclarationS( _varDeclarationS ),
            methodDeclarationS( _methodDeclarationS )
    {}

    void Accept( IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const CTerminalIdentifier> className;
    const std::unique_ptr<const IExtension> extension;
    const std::unique_ptr<const IVarDeclarationS> varDeclarationS;
    const std::unique_ptr<const IMethodDeclarationS> methodDeclarationS;
};


