// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>

#include "StackFrame/FrameBuilder.hpp"
#include "StackFrame/FramesHolder.hpp"

#include "IRTree/IRTVisualiser.h"
#include "IRTree/IRTBuilder.h"
#include "parser/parser.h"
#include "AST/ASTBuilder.h"
#include "SymbolTable/SymbolTableBuilder.h"

int main( int argc, char** argv ) {
    freopen( argv[1], "r", stdin );

    IAcceptable * goal = nullptr;
    yyparse( goal, stdout );

    CASTBuilder * builder = new CASTBuilder();
    const CGoal * newGoal = builder->BuildAST( static_cast<const CGoal*>( goal ) );

    CSymbolTableBuilder tableBuilder;
    std::unique_ptr<CSymbolTable> table = tableBuilder.Build( newGoal );

    CFrameBuilder* frameBuilder = new CFrameBuilder();
    const CFramesHolder* framesHolder = frameBuilder->build( table );

    IRTree::CIRTBuilder irtBuilder;
    IRTree::CIRTVisualiser irtVisualiser( "build/irt.gv" );

    irtVisualiser.printIRT( irtBuilder.BuildAST( newGoal, table.get(), framesHolder ) );

    return 0;
}
