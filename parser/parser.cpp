// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <cstdio>
#include <cstring>

#include "parser.h"
#include "parser.tab.hpp"

void yyerror( IAcceptable * & node, FILE * fout, char const * msg );
void parserProcessRule( FILE * fout, const char * left, const char * right );
void parserPrintDebugMessage( FILE * fout, const char * left, const char * right );

void yyerror( IAcceptable * & node, FILE * fout, char const * msg )
{
	fprintf( stderr,"ошибка %d:%d : %s\n", yylloc.first_line, yylloc.first_column, msg );
}

void parserProcessRule( FILE * fout, const char * left, const char * right )
{
#ifdef PARSER_DEBUG
	parserPrintDebugMessage( fout, left, right );
#endif
}

void parserPrintDebugMessage( FILE * fout, const char * left, const char * right )
{
	const char * fmt = "PARSER_DEBUG: %s <= %s\n";
	fprintf( fout, fmt, left, right );
}
