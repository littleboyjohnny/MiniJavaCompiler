#ifndef MINIJAVACOMPILER_CLASSDECLARATION_HPP
#define MINIJAVACOMPILER_CLASSDECLARATION_HPP

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

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const className;
    const IExtension * const extension;
    const IVarDeclarationS * const varDeclarationS;
    const IMethodDeclarationS * const methodDeclarationS;
};

#endif //MINIJAVACOMPILER_CLASSDECLARATION_HPP
