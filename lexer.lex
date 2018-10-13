%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include "parser.tab.h"


long TT_char_pos = 1;

#define YY_USER_ACTION \
	if (yylloc.first_line < yylineno) \
		TT_char_pos = 1; \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = TT_char_pos; \
	TT_char_pos = TT_char_pos + yyleng;

%}

WS [ \n\t\v]*

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

NEW	new{WS}

THIS	this{WS}

TYPE	(int|boolean){WS}

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

{IF}	{return IF;}

{ELSE}	{return ELSE;}

{WHILE}	{return WHILE;}

{INTLITERAL}	{yylval.intVal = atoi(yytext); return INTLITERAL;}

{TRUE}	{return _TRUE;}

{FALSE}	{return _FALSE;}

{PUBLIC}	{return PUBLIC;}

{STATIC}	{return STATIC;}

{EXTENDS}	{return EXTENDS;}

{VOID}	{return VOID;}

{MAIN}	{return MAIN;}

{NEW}	{return NEW;}

{THIS}	{return THIS;}

{TYPE}	{return TYPE;}

{CLASS} {return CLASS;}

{LCURLYBRACE}	{return LCURLYBRACE;}

{RCURLYBRACE}	{return RCURLYBRACE;}

{LPAREN}	{return LPAREN;}

{RPAREN}	{return RPAREN;}

{LSQUAREBRACKET}	{return LSQUAREBRACKET;}

{RSQUAREBRACKET}	{return RSQUAREBRACKET;}

{SEMICOLON}	{return SEMICOLON;}

{COMMA}	{return COMMA;}

{DOT}	{return DOT;}

{EQUALS}	{return EQUALS;}

{NOT}	{return NOT;}

{LESS}	{return LESS;}

{AND}	{return AND;}

{PLUS}	{return PLUS;}

{MINUS}	{return MINUS;}

{MULTIPLY}	{return MULTIPLY;}

{IDENTIFIER}	{yylval.stringVal = yytext;return IDENTIFIER;}

%%
