#include "parser/parser.h"
#include "AST/include/ASTVisualiser.h"
#include <iostream>

extern int yyparse(void*&);

int main( int argc, char** argv )
{
    freopen( argv[1], "r", stdin );
    void * goal = nullptr;
    yyparse( goal );
    CASTVisualiser visualiser( "ast.gv" );
    ((CGoal*)goal)->Accept( &visualiser );
    // std::cout << goal << std::endl;
    return 0;
}

