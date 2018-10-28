#ifndef MINIJAVACOMPILER_METHODDECLARATIONS_HPP
#define MINIJAVACOMPILER_METHODDECLARATIONS_HPP

#include "../interfaces/IMethodDeclarationS.h"
#include "../interfaces/IVisitor.h"
#include "../interfaces/IMethodDeclaration.h"

class CMethodDeclarationS : public IMethodDeclarationS {
public:
    CMethodDeclarationS( const IMethodDeclarationS * const _methodDeclarationS,
            const IMethodDeclaration * const _methodDeclaration ) :
            methodDeclarationS( _methodDeclarationS ),
            methodDeclaration( _methodDeclaration )
    {}

    void Accept( IVisitor * visitor )
    {
        visitor->Visit( this );
    }

private:
    const IMethodDeclarationS * const methodDeclarationS;
    const IMethodDeclaration * const methodDeclaration;
};

#endif //MINIJAVACOMPILER_METHODDECLARATIONS_HPP
