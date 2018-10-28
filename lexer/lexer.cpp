#include "lexer.h"

#include <cstdio>
#include <cstdlib>

extern int yylineno;

long TT_char_pos = 1;
long TT_char_prev_pos = 0;

#ifdef LEXER_MAIN
int main( int argc, char** argv )
{
	freopen( argv[1], "r", stdin );
	while( yylex() );
	return 0;
}
#endif

void lexerPrintDebugMessage( const char * msg )
{
	const char * fmt = "LEXER_DEBUG: %s(%d, %d, %d)\n";
	printf( fmt, msg, yylineno, TT_char_prev_pos, TT_char_pos );
}

void lexerProcessToken( int token, const char * msg )
{
#ifdef LEXER_DEBUG
	lexerPrintDebugMessage( msg );
#endif
}