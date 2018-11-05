#ifndef MINIJAVACOMPILER_CLASSDECLARATIONLIST_HPP
#define MINIJAVACOMPILER_CLASSDECLARATIONLIST_HPP

#include "../interfaces/IClassDeclarationS.h"
#include "../interfaces/IClassDeclaration.h"
#include "../core/IVisitor.h"

#include <vector>

class CClassDeclarationList : public IClassDeclarationS {
public:
    CClassDeclarationList()
    {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    mutable std::vector<const IClassDeclaration *> children;
};

#endif //MINIJAVACOMPILER_CLASSDECLARATIONLIST_HPP
