#include <iostream>

#include <parser.h>
#include <ASTBuilder.h>
#include <ASTVisualiser.h>
#include <SymbolTableBuilder.h>
#include "CSymbolTableVisualizer.h"
#include "TypeChecker.h"


int main( int argc, char** argv )
{
    freopen( argv[1], "r", stdin );

    IAcceptable * goal = nullptr;
    yyparse( goal, stdout );

    CASTBuilder * builder = new CASTBuilder();
    const CGoal * newGoal = builder->BuildAST( static_cast<const CGoal*>( goal ) );

    CSymbolTableBuilder tableBuilder;
    std::unique_ptr<CSymbolTable> table = tableBuilder.Build( newGoal );

    CSymbolTableVisualizer visualizer;
    visualizer.Visuzlize( table.get() );

    CTypeChecker typeChecker;
    typeChecker.Run( newGoal, table.get() );

    return 0;
}

