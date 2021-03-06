#pragma once

#include <memory>

#include "../interfaces/IGoal.h"
#include "../interfaces/IMainClass.h"
#include "../interfaces/IClassDeclarationS.h"
#include "../core/IVisitor.h"

class CGoal : public IGoal {
public:
    CGoal( const IMainClass* const mainClass1, const IClassDeclarationS* const classDeclarationS1 ) :
            mainClass( mainClass1 ),
            classDeclarationS( classDeclarationS1 )
            {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IMainClass> mainClass;
    const std::unique_ptr<const IClassDeclarationS> classDeclarationS;
};


