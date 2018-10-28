#ifndef MINIJAVACOMPILER_GOAL_H
#define MINIJAVACOMPILER_GOAL_H

#include "../interfaces/IGoal.h"
#include "../interfaces/IMainClass.h"
#include "../interfaces/IClassDeclarationS.h"
#include "../interfaces/IVisitor.h"

class CGoal : public IGoal {
public:
    CGoal( const IMainClass* const mainClass1, const IClassDeclarationS* const classDeclarationS1 ) :
            mainClass( mainClass1 ),
            classDeclarationS( classDeclarationS1 )
            {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IMainClass* const mainClass;
    const IClassDeclarationS* const classDeclarationS;
};

#endif //MINIJAVACOMPILER_GOAL_H