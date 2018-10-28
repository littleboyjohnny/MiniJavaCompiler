#ifndef MINIJAVACOMPILER_CLASSDECLARATIONS_HPP
#define MINIJAVACOMPILER_CLASSDECLARATIONS_HPP

#include "../interfaces/IClassDeclarationS.h"
#include "../interfaces/IClassDeclaration.h"
#include "../interfaces/IVisitor.h"

class CClassDeclarationS : public IClassDeclarationS {
public:
    CClassDeclarationS( const IClassDeclarationS * const _classDeclarationS,
            const IClassDeclaration * const _classDeclaration ) :
            classDeclarationS( _classDeclarationS ),
            classDeclaration( _classDeclaration )
    {}

    void Accept( IVisitor * visitor )
    {
        visitor->Visit( this );
    }

    const IClassDeclarationS * const classDeclarationS;
    const IClassDeclaration * const classDeclaration;
};

#endif //MINIJAVACOMPILER_CLASSDECLARATIONS_HPP
