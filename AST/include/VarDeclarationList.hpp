#ifndef MINIJAVACOMPILER_VARDECLARATIONLIST_HPP
#define MINIJAVACOMPILER_VARDECLARATIONLIST_HPP

#include <vector>

#include "../interfaces/IVarDeclarationS.h"
#include "../core/IVisitor.h"
#include "../interfaces/IVarDeclaration.h"

class CVarDeclarationList : public IVarDeclarationS {
public:
    CVarDeclarationList()
    {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    mutable std::vector<const IVarDeclaration *> children;
};

#endif //MINIJAVACOMPILER_VARDECLARATIONLIST_HPP
