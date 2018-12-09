#include "FrameBuilder.hpp"
#include "FramesHolder.hpp"


int main() {
    freopen( argv[1], "r", stdin );

    IAcceptable * goal = nullptr;
    yyparse( goal, stdout );

    CASTBuilder * builder = new CASTBuilder();
    const CGoal * newGoal = builder->BuildAST( static_cast<const CGoal*>( goal ) );

    CSymbolTableBuilder tableBuilder;
    std::unique_ptr<CSymbolTable> table = tableBuilder.Build( newGoal );

    CFrameBuilder* frameBuilder = new CFrameBuilder();
    const CFramesHolder* framesHolder = frameBuilder->build(table);
}