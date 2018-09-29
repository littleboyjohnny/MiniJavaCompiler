%{
#include <stdio.h>
%}

%option noyywrap
%option yylineno

WS [ \n\t\v]

GOAL	{MAINCLASS}

MAINCLASS	class{WS}+ForCompiler{WS}*\{(.|\n)*\}

%%

{WS}	;

{MAINCLASS}	{printf("MAINCLASS\n");}


%%
/*

WS [ \t\v]

STATE (int|bool)
INTEGER integer

%%

{WS}	;

{STATE}	{printf("STATE: %s\n", yytext);}

{INTEGER} {printf("INTEGER: %s\n", yytext);}

\n	yylineno++;

%%

GOAL	{MAINCLASS}({CLASSDECLARATION})*
MAINCLASS	"class"{IDENTIFIER}"{""public""static""void""main""(""String""[""]"{IDENTIFIER}")""{"{STATEMENT}"}""}"
CLASSDECLARATION	.*?
STATEMENT	.*?
TYPE	"int""[""]"|"boolean"|"int"|{IDENTIFIER}
IDENTIFIER	({LETTER}|_)({LETTER}|{DIGIT}|_)*
*/


//{TYPE}	{printf("Saw a TYPE: %s at line %d\n", yytext, yylineno);}
//{IDENTIFIER}	{printf("Saw a IDENTIFIER: %s at line %d\n", yytext, yylineno);}

int main(void)
{
	/* Call the lexer, then quit. */
	yylex();
	return 0;
}
