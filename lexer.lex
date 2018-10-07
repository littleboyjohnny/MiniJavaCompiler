%{
#include <stdio.h>
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

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

VOID	void{WS}

MAIN	main{WS}

NEW	new{WS}

THIS	this{WS}

TYPE	(int|boolean){WS}

CLASS class{WS}

LCURLYBRACE	"{"{WS}

RCURLYBRACE	"}"{WS}

LPAREN	"("{WS}

RPAREN	")"{WS}

LSQUAREBRACKET	"["{WS}

RSQUAREBRACKET	"]"{WS}

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

{INTLITERAL}	{yylval=atoi(yytext); return INTLITERAL;}

{TRUE}	{return _TRUE;}

{FALSE}	{return _FALSE;}

{PUBLIC}	{return PUBLIC;}

{STATIC}	{return STATIC;}

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

{IDENTIFIER}	{yylval = yytext;return IDENTIFIER;}

%%
