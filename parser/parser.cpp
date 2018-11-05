#include <cstdio>
#include <cstring>

#include "parser.h"

void yyerror( IAcceptable * & node, char const * msg );
void parserProcessRule( const char * left, const char * right );
void parserPrintDebugMessage( const char * left, const char * right );


void yyerror( IAcceptable * & node, char const * msg )
{
	fprintf( stderr,"ошибка: %s\n", msg );
}

void parserProcessRule( const char * left, const char * right )
{
#ifdef PARSER_DEBUG
	parserPrintDebugMessage( left, right );
#endif
}

void parserPrintDebugMessage( const char * left, const char * right )
{
	const char * fmt = "PARSER_DEBUG: %s <= %s\n";
	printf( fmt, left, right );
}
