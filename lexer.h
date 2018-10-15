#define LEXER_PROCESS_TOKEN(token) lexerProcessToken(token, #token)

#define YY_USER_ACTION \
	TT_char_prev_pos = TT_char_pos; \
	if (yylloc.first_line < yylineno) \
		TT_char_pos = 1; \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = TT_char_pos; \
	TT_char_pos = TT_char_pos + yyleng;


long TT_char_pos = 1;
long TT_char_prev_pos = 0;


void lexerPrintDebugMessage(const char * msg)
{
	const char * fmt = "LEXER_DEBUG: %s(%d, %d, %d)\n";
	printf(fmt, msg, yylineno, TT_char_prev_pos, TT_char_pos);
}


void lexerProcessToken(int token, const char * msg)
{
#ifdef LEXER_DEBUG
	lexerPrintDebugMessage(msg);
#endif
}

