#include <cstdio>
#include <cstring>

#include "parser.h"

void yyerror( IAcceptable * & node, FILE * fout, char const * msg );
void parserProcessRule( FILE * fout, const char * left, const char * right );
void parserPrintDebugMessage( FILE * fout, const char * left, const char * right );

void yyerror( IAcceptable * & node, FILE * fout, char const * msg )
{
	fprintf( stderr,"ошибка: %s\n", msg );
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
