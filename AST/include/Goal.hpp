#ifndef MINIJAVACOMPILER_GOAL_H
#define MINIJAVACOMPILER_GOAL_H

#include "IGoal.h"
#include "../MainClass/IMainClass.h"
#include "../ClassDeclarationS/IClassDeclarationS.h"
#include "../Visitor/IVisitor.h"

class Goal : public IGoal {
public:
    Goal( const IMainClass* const mainClass1, const IClassDeclarationS* const classDeclarationS1 ) :
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
