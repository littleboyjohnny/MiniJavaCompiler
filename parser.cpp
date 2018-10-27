#include "parser.h"

#include <cstdio>
#include <cstring>

#ifdef PARSER_MAIN
int main( int argc, char** argv )
{
	freopen( argv[1], "r", stdin );
	yyparse();
	return 0;
}
#endif

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
