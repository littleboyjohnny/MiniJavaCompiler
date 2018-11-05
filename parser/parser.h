#include "../AST/ASTIncludes.h"
#include "../AST/ASTInterfaces.h"

#include "../AST/core/TerminalIntliteral.hpp"
#include "../AST/core/TerminalIdentifier.hpp"

extern "C" int yyparse( IAcceptable * & node );
