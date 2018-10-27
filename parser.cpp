#include "parser.h"

#include <stdio.h>
#include <string.h>

void yyerror( const char * str )
{
	fprintf( stderr,"ошибка: %s\n", str );
}

void parserPrintDebugMessage( const char * left, const char * right )
{
	char fmt[100] = "";
	if( strcmp(right, "") == 0 ) {
		strcpy( fmt, "PARSER_DEBUG: %s\n" );
	} else {
		strcpy( fmt, "PARSER_DEBUG: %s = %s\n" );
	}
	printf( fmt, left, right );
}


void parserProcessRule( const char * left, const char * right )
{
#ifdef PARSER_DEBUG
	parserPrintDebugMessage( left, right );
#endif
}

