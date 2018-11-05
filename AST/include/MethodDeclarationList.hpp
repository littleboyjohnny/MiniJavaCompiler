#ifndef MINIJAVACOMPILER_METHODDECLARATIONLIST_HPP
#define MINIJAVACOMPILER_METHODDECLARATIONLIST_HPP

#include "../interfaces/IMethodDeclarationS.h"
#include "../interfaces/IVisitor.h"
#include "../interfaces/IMethodDeclaration.h"

#include <vector>

class CMethodDeclarationList : public IMethodDeclarationS {
public:
    CMethodDeclarationList() {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    mutable std::vector<const IMethodDeclaration *> children;
};

#endif //MINIJAVACOMPILER_METHODDECLARATIONLIST_HPP
