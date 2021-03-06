#include <iostream>

#include "parser/parser.h"
#include "AST/ASTBuilder.h"
#include "AST/ASTVisualiser.h"


int main( int argc, char** argv )
{
    freopen( argv[1], "r", stdin );

    IAcceptable * goal = nullptr;
    yyparse( goal, stdout );

    CASTBuilder * builder = new CASTBuilder();
    const CGoal * newGoal = builder->BuildAST(static_cast< const CGoal * >(goal));

    CASTVisualiser visualiser( "build/ast.gv" );
    newGoal->Accept(&visualiser);

    return 0;
}

