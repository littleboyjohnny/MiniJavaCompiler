#include <cstdio>
#include <cstdlib>

#include "lexer.h"

long TT_char_pos = 1;
long TT_char_prev_pos = 0;

void lexerProcessToken( const char * msg );
void lexerPrintDebugMessage( const char * msg );

void lexerProcessToken( const char * msg )
{
#ifdef LEXER_DEBUG
	lexerPrintDebugMessage( msg );
#endif
}

void lexerPrintDebugMessage( const char * msg )
{
	const char * fmt = "LEXER_DEBUG: %s(%d, %d, %d)\n";
	printf( fmt, msg, yylineno, TT_char_prev_pos, TT_char_pos );
}
