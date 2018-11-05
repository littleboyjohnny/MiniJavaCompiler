#include "parser/parser.h"
#include "AST/ASTBuilder.h"
#include "AST/ASTVisualiser.h"
#include <iostream>

extern int yyparse(IAcceptable*& node);

int main( int argc, char** argv )
{
    freopen( argv[1], "r", stdin );
    IAcceptable * goal = nullptr;
    yyparse( goal );
    CASTBuilder * builder = new CASTBuilder();
    const CGoal * newGoal = builder->BuildAST(static_cast< const CGoal * >(goal));
    CASTVisualiser visualiser("build/ast.gv");
    newGoal->Accept(&visualiser);
    //((CGoal*)goal)->Accept( &builder );
    // std::cout << goal << std::endl;
    return 0;
}

