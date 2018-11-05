#ifndef MINIJAVACOMPILER_GOAL_H
#define MINIJAVACOMPILER_GOAL_H

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

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IMainClass* const mainClass;
    const IClassDeclarationS* const classDeclarationS;
};

#endif //MINIJAVACOMPILER_GOAL_H
