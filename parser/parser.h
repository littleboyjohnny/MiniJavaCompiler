#include "../AST/ASTIncludes.h"
#include "../AST/ASTInterfaces.h"

#include "../AST/core/TerminalIntliteral.hpp"
#include "../AST/core/TerminalIdentifier.hpp"

#include <stdio.h>

extern int yyparse( IAcceptable * & node, FILE * fout );
