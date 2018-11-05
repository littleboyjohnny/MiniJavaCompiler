#include "../AST/include/ASTIncludes.h"
#include "../AST/interfaces/ASTInterfaces.h"

#include "../AST/include/TerminalIntliteral.hpp"
#include "../AST/include/TerminalIdentifier.hpp"

extern "C" int yyparse( IAcceptable * & node );
