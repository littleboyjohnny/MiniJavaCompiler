#include "../parser/parser.tab.h"

#define LEXER_PROCESS_TOKEN(token) lexerProcessToken(token, #token)

#define YY_USER_ACTION \
	TT_char_prev_pos = TT_char_pos; \
	if (yylloc.first_line < yylineno) \
		TT_char_pos = 1; \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = TT_char_pos; \
	TT_char_pos = TT_char_pos + yyleng;

extern long TT_char_pos;
extern long TT_char_prev_pos;


#ifdef LEXER_MAIN
int main( int argc, char** argv );
#endif

extern "C" int yylex();

void lexerPrintDebugMessage( const char * msg );

void lexerProcessToken( int token, const char * msg );
