%option noyywrap
%option yylineno

%{
#include "lexer.h"
#include "../parser/parser.tab.h"

#define YY_USER_ACTION \
	TT_char_prev_pos = TT_char_pos; \
	if( yylloc.first_line < yylineno ) \
		TT_char_pos = 1; \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = TT_char_pos; \
	TT_char_pos = TT_char_pos + yyleng;

#define LEXER_PROCESS_TOKEN( token ) lexerProcessToken( token, #token )

void lexerProcessToken( int token, const char * msg );
void lexerPrintDebugMessage( const char * msg );
%}

WS [ \t\v]*

IDENTIFIER	[a-zA-Z_][a-zA-Z0-9_]*{WS}

IF	if{WS}

ELSE	else{WS}

WHILE	while{WS}

INTLITERAL	(([1-9][0-9]*)|(0[0-7]*)|(O[xX][0-9a-fA-F]*)){WS}

TRUE	true{WS}

FALSE	false{WS}

PUBLIC	public{WS}

STATIC	static{WS}

EXTENDS	extends{WS}

VOID	void{WS}

MAIN	main{WS}

RETURN return{WS}

NEW	new{WS}

THIS	this{WS}

PRINTLN	"System.out.println"{WS}

DOTLENGTH	".length"{WS}

STRING	String{WS}

INT	int{WS}

BOOLEAN	boolean{WS}

CLASS class{WS}

LCURLYBRACE	"{"

RCURLYBRACE	"}"

LPAREN	"("

RPAREN	")"

LSQUAREBRACKET	"["

RSQUAREBRACKET	"]"

SEMICOLON	";"{WS}

COMMA	","{WS}

DOT	"."{WS}

EQUALS	"="{WS}

NOT	"!"{WS}

LESS	"<"{WS}

AND	"&&"{WS}

PLUS	"+"{WS}

MINUS	"-"{WS}

MULTIPLY	"*"{WS}

%%

"\n"	{ lexerProcessToken( -1, "\\n" ); }

{WS}	{ lexerProcessToken( -2, "WS" ); }

{IF}	{ LEXER_PROCESS_TOKEN(IF); return IF; }

{ELSE}	{ LEXER_PROCESS_TOKEN(ELSE); return ELSE; }

{WHILE}	{ LEXER_PROCESS_TOKEN(WHILE); return WHILE; }

{INTLITERAL}	{ LEXER_PROCESS_TOKEN(INTLITERAL); yylval.terminalIntliteral = new CTerminalIntliteral(atoi(yytext)); return INTLITERAL; }

{TRUE}	{ LEXER_PROCESS_TOKEN(_TRUE); return _TRUE; }

{FALSE}	{ LEXER_PROCESS_TOKEN(_FALSE); return _FALSE; }

{PUBLIC}	{ LEXER_PROCESS_TOKEN(PUBLIC); return PUBLIC; }

{STATIC}	{ LEXER_PROCESS_TOKEN(STATIC); return STATIC; }

{EXTENDS}	{ LEXER_PROCESS_TOKEN(EXTENDS); return EXTENDS; }

{VOID}	{ LEXER_PROCESS_TOKEN(VOID); return VOID; }

{MAIN}	{ LEXER_PROCESS_TOKEN(MAIN); return MAIN; }

{RETURN}	{ LEXER_PROCESS_TOKEN(RETURN); return RETURN; }

{NEW}	{ LEXER_PROCESS_TOKEN(NEW); return NEW; }

{THIS}	{ LEXER_PROCESS_TOKEN(THIS); return THIS; }

{PRINTLN}	{ LEXER_PROCESS_TOKEN(PRINTLN); return PRINTLN; }

{DOTLENGTH}	{ LEXER_PROCESS_TOKEN(DOTLENGTH); return DOTLENGTH; }

{STRING}	{ LEXER_PROCESS_TOKEN(STRING); return STRING; }

{INT}	{ LEXER_PROCESS_TOKEN(INT); return INT; }

{BOOLEAN}	{ LEXER_PROCESS_TOKEN(BOOLEAN); return BOOLEAN; }

{CLASS} { LEXER_PROCESS_TOKEN(CLASS); return CLASS; }

{LCURLYBRACE}	{ LEXER_PROCESS_TOKEN(LCURLYBRACE); return LCURLYBRACE; }

{RCURLYBRACE}	{ LEXER_PROCESS_TOKEN(RCURLYBRACE); return RCURLYBRACE; }

{LPAREN}	{ LEXER_PROCESS_TOKEN(LPAREN); return LPAREN; }

{RPAREN}	{ LEXER_PROCESS_TOKEN(RPAREN); return RPAREN; }

{LSQUAREBRACKET}	{ LEXER_PROCESS_TOKEN(LSQUAREBRACKET); return LSQUAREBRACKET; }

{RSQUAREBRACKET}	{ LEXER_PROCESS_TOKEN(RSQUAREBRACKET); return RSQUAREBRACKET; }

{SEMICOLON}	{ LEXER_PROCESS_TOKEN(SEMICOLON); return SEMICOLON;}

{COMMA}	{ LEXER_PROCESS_TOKEN(COMMA); return COMMA; }

{DOT}	{ LEXER_PROCESS_TOKEN(DOT); return DOT; }

{EQUALS}	{ LEXER_PROCESS_TOKEN(EQUALS); return EQUALS; }

{NOT}	{ LEXER_PROCESS_TOKEN(NOT); return NOT; }

{LESS}	{ LEXER_PROCESS_TOKEN(LESS); return LESS; }

{AND}	{ LEXER_PROCESS_TOKEN(AND); return AND; }

{PLUS}	{ LEXER_PROCESS_TOKEN(PLUS); return PLUS; }

{MINUS}	{ LEXER_PROCESS_TOKEN(MINUS); return MINUS; }

{MULTIPLY}	{ LEXER_PROCESS_TOKEN(MULTIPLY); return MULTIPLY; }

{IDENTIFIER}	{ LEXER_PROCESS_TOKEN(IDENTIFIER); yylval.terminalIdentifier = new CTerminalIdentifier(yytext, yyleng); return IDENTIFIER; }

%%

//{EOF}	{return EOF;}
