%{
#include <stdio.h>
%}

%option noyywrap
%option yylineno

WS [ \n\t\v]

GOAL	{MAINCLASS}{WS}+{CLASSDECLARATION}*

MAINCLASS	"class"{WS}+{IDENTIFIER}{WS}*"{"{WS}*"public"{WS}+"static"{WS}+"void"{WS}+"main"{WS}*"("{WS}*"String"{WS}*"["{WS}*"]"{WS}*{IDENTIFIER}{WS}*")"{WS}*"{"{WS}*{STATEMENT}{WS}*"}"{WS}*"}"

CLASSDECLARATION	"class"{WS}+{IDENTIFIER}{WS}*({WS}*"extends"{WS}+{IDENTIFIER})?{WS}*"{"{WS}*({VARDECLARATION}|{WS})*({METHODDECLARATION}|{WS})*{WS}*"}"

VARDECLARATION	{TYPE}{WS}+{IDENTIFIER}{WS}*";"

METHODDECLARATION	"public"{WS}+{TYPE}{WS}+{IDENTIFIER}{WS}*"("{WS}*({TYPE}{WS}+{IDENTIFIER}{WS}*(","{WS}*{TYPE}{WS}+{IDENTIFIER})*)?{WS}*")"{WS}*"{"{WS}*({VARDECLARATION}|{WS})*({STATEMENT}|{WS})*"return"{WS}+{EXPRESSION}{WS}*";"{WS}*"}"

TYPE	"int""[""]"|"boolean"|"int"|{IDENTIFIER}

STATEMENT	("{"({STATEMENT}|{WS})*"}")|("if"{WS}*"("{WS}*{EXPRESSION}{WS}*")"{WS}*{STATEMENT}{WS}+"else"{WS}+{STATEMENT})|("while"{WS}*"("{WS}*{EXPRESSION}{WS}*")"{WS}*{STATEMENT})|("System.out.println"{WS}*"("{WS}*{EXPRESSION}{WS}*")"{WS}*";")|({IDENTIFIER}{WS}*"="{WS}*{EXPRESSION}{WS}*";")|({IDENTIFIER}{WS}*"["{WS}*{EXPRESSION}{WS}*"]"{WS}*"="{WS}*{EXPRESSION}{WS}*";")

EXPRESSION	({EXPRESSION}{WS}*("&&"|"<"|"+"|"-"|"*"){WS}*{EXPRESSION})|({EXPRESSION}{WS}*"["{WS}*{EXPRESSION}{WS}*"]")|({EXPRESSION}".""length")|({EXPRESSION}"."{IDENTIFIER}"("{WS}*({EXPRESSION}{WS}*(","{WS}*{EXPRESSION})*)?{WS}*")")|(([1-9][0-9]*)|(0[0-7]*)|(O[xX][0-9a-fA-F]*))|"true"|"false"|{IDENTIFIER}|"this"|("new"{WS}+"int"{WS}*"["{WS}*{EXPRESSION}{WS}*"]")|("new"{WS}+{IDENTIFIER}{WS}*"("{WS}*")")|("!"{WS}*{EXPRESSION})|("("{WS}*{EXPRESSION}{WS}*")")

IDENTIFIER	[a-zA-Z_][a-zA-Z0-9_]*

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
