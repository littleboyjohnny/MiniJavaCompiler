#ifndef MINIJAVACOMPILER_VARDECLARATIONS_HPP
#define MINIJAVACOMPILER_VARDECLARATIONS_HPP

#include "../interfaces/IVarDeclarationS.h"
#include "../interfaces/IVisitor.h"
#include "../interfaces/IVarDeclaration.h"

class CVarDeclarationS : public IVarDeclarationS {
public:
    CVarDeclarationS( const IVarDeclarationS * const _varDeclarationS,
            const IVarDeclaration * const _varDeclaration ) :
            varDeclarationS( _varDeclarationS ),
            varDeclaration( _varDeclaration )
    {}

    void Accept( IVisitor * visitor )
    {
        visitor->Visit( this );
    }

private:
    const IVarDeclarationS * const varDeclarationS;
    const IVarDeclaration * const varDeclaration;
};

#endif //MINIJAVACOMPILER_VARDECLARATIONS_HPP
