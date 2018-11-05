%option noyywrap
%option yylineno

%{
#include "lexer.h"
#include "parser.tab.hpp"

#define YY_USER_ACTION \
	TT_char_prev_pos = TT_char_pos; \
	if( yylloc.first_line < yylineno ) \
		TT_char_pos = 1; \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = TT_char_pos; \
	TT_char_pos = TT_char_pos + yyleng;

void lexerProcessToken( const char * msg );
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

"\n"	{ lexerProcessToken( "NEWLINE" ); }

{WS}	{ lexerProcessToken( "WS" ); }

{IF}	{ lexerProcessToken( "IF" ); return IF; }

{ELSE}	{ lexerProcessToken( "ELSE" ); return ELSE; }

{WHILE}	{ lexerProcessToken( "WHILE" ); return WHILE; }

{INTLITERAL}	{ lexerProcessToken( "INTLITERAL" ); yylval.terminalIntliteral = new CTerminalIntliteral(atoi(yytext)); return INTLITERAL; }

{TRUE}	{ lexerProcessToken( "_TRUE" ); return _TRUE; }

{FALSE}	{ lexerProcessToken( "_FALSE" ); return _FALSE; }

{PUBLIC}	{ lexerProcessToken( "PUBLIC" ); return PUBLIC; }

{STATIC}	{ lexerProcessToken( "STATIC" ); return STATIC; }

{EXTENDS}	{ lexerProcessToken( "EXTENDS" ); return EXTENDS; }

{VOID}	{ lexerProcessToken( "VOID" ); return VOID; }

{MAIN}	{ lexerProcessToken( "MAIN" ); return MAIN; }

{RETURN}	{ lexerProcessToken( "RETURN" ); return RETURN; }

{NEW}	{ lexerProcessToken( "NEW" ); return NEW; }

{THIS}	{ lexerProcessToken( "THIS" ); return THIS; }

{PRINTLN}	{ lexerProcessToken( "PRINTLN" ); return PRINTLN; }

{DOTLENGTH}	{ lexerProcessToken( "DOTLENGTH" ); return DOTLENGTH; }

{STRING}	{ lexerProcessToken( "STRING" ); return STRING; }

{INT}	{ lexerProcessToken( "INT" ); return INT; }

{BOOLEAN}	{ lexerProcessToken( "BOOLEAN" ); return BOOLEAN; }

{CLASS} { lexerProcessToken( "CLASS" ); return CLASS; }

{LCURLYBRACE}	{ lexerProcessToken( "LCURLYBRACE" ); return LCURLYBRACE; }

{RCURLYBRACE}	{ lexerProcessToken( "RCURLYBRACE" ); return RCURLYBRACE; }

{LPAREN}	{ lexerProcessToken( "LPAREN" ); return LPAREN; }

{RPAREN}	{ lexerProcessToken( "RPAREN" ); return RPAREN; }

{LSQUAREBRACKET}	{ lexerProcessToken( "LSQUAREBRACKET" ); return LSQUAREBRACKET; }

{RSQUAREBRACKET}	{ lexerProcessToken( "RSQUAREBRACKET" ); return RSQUAREBRACKET; }

{SEMICOLON}	{ lexerProcessToken( "SEMICOLON" ); return SEMICOLON;}

{COMMA}	{ lexerProcessToken( "COMMA" ); return COMMA; }

{DOT}	{ lexerProcessToken( "DOT" ); return DOT; }

{EQUALS}	{ lexerProcessToken( "EQUALS" ); return EQUALS; }

{NOT}	{ lexerProcessToken( "NOT" ); return NOT; }

{LESS}	{ lexerProcessToken( "LESS" ); return LESS; }

{AND}	{ lexerProcessToken( "AND" ); return AND; }

{PLUS}	{ lexerProcessToken( "PLUS" ); return PLUS; }

{MINUS}	{ lexerProcessToken( "MINUS" ); return MINUS; }

{MULTIPLY}	{ lexerProcessToken( "MULTIPLY" ); return MULTIPLY; }

{IDENTIFIER}	{ lexerProcessToken( "IDENTIFIER" ); yylval.terminalIdentifier = new CTerminalIdentifier(yytext, yyleng); return IDENTIFIER; }

%%

//{EOF}	{return EOF;}
