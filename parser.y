%{
#include <stdio.h>
#include <string.h>
#include "parser.h"


#ifdef PARSER_MAIN
int main() {
	yyparse();
	return 0;
}
#endif

%}

%locations
%verbose

%union {
	int intVal;
	char *stringVal;
}

%token <stringVal> IDENTIFIER 
%token IF ELSE WHILE
%token <intVal> INTLITERAL
%token _TRUE _FALSE PUBLIC STATIC EXTENDS VOID MAIN RETURN NEW THIS PRINTLN DOTLENGTH STRING INT BOOLEAN CLASS LCURLYBRACE RCURLYBRACE LPAREN RPAREN LSQUAREBRACKET RSQUAREBRACKET SEMICOLON COMMA DOT EQUALS NOT LESS AND PLUS MINUS MULTIPLY

%left AND
%left LESS
%right NOT
%left PLUS MINUS
%left MULTIPLY
%left LSQUAREBRACKET
%left DOT DOTLENGTH


%%

Goal: MainClass ClassDeclarationS {printf("Goal\n");}
    ;

ClassDeclarationS: %empty
	| ClassDeclarationS ClassDeclaration
	;

MainClass: CLASS IDENTIFIER LCURLYBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LSQUAREBRACKET RSQUAREBRACKET IDENTIFIER RPAREN LCURLYBRACE StatementS RCURLYBRACE RCURLYBRACE {printf("MainClass\n");}
    ;

ClassDeclaration: CLASS IDENTIFIER Extension LCURLYBRACE VarDeclarationS MethodDeclarationS RCURLYBRACE {printf("ClassDeclaration\n");}
    ;

Extension: %empty
	| EXTENDS IDENTIFIER {printf("EXTENDS IDENTIFIER\n");}
	;

VarDeclarationS: %empty
	| VarDeclarationS VarDeclaration {printf("VarDeclarationS VarDeclaration\n");}
	;

VarDeclaration: Type IDENTIFIER SEMICOLON {printf("Type IDENTIFIER SEMICOLON: %s\n", yylval);}
    ;

MethodDeclarationS: %empty
	| MethodDeclarationS MethodDeclaration {printf("MethodDeclarationS MethodDeclaration\n");}
	;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE	{printf("PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE\n");}
    ;

Params: %empty
	| Type IDENTIFIER AdditionalParamS {printf("Type IDENTIFIER AdditionalParamS\n");}
	;

AdditionalParamS: %empty
	| AdditionalParamS AdditionalParam {printf("AdditionalParamS AdditionalParam\n");}
	;

AdditionalParam: COMMA Type IDENTIFIER {printf("COMMA Type IDENTIFIER\n");}
	;

Type: INT LSQUAREBRACKET RSQUAREBRACKET {printf("TYPE INT LSQUAREBRACKET RSQUAREBRACKET\n");}//"int" "[" "]" 
    | BOOLEAN {printf("TYPE BOOLEAN\n");}
    | INT {printf("TYPE INT\n");}
    | IDENTIFIER {printf("TYPE IDENTIFIER:\n");}
    ;

StatementS: %empty
	| Statement StatementS {printf("StatementS Statement\n");}
	;

Statement: LCURLYBRACE StatementS RCURLYBRACE {printf("LCURLYBRACE StatementS RCURLYBRACE\n");}
    | IF LPAREN Expression RPAREN Statement ELSE Statement {printf("IF LPAREN Expression RPAREN Statement ELSE Statement\n");}
    | WHILE LPAREN Expression RPAREN Statement {printf("WHILE LPAREN Expression RPAREN Statement\n");}
    | PRINTLN LPAREN Expression RPAREN SEMICOLON {printf("PRINTLN LPAREN Expression RPAREN SEMICOLON\n");}
    | IDENTIFIER EQUALS Expression SEMICOLON {printf("IDENTIFIER EQUALS Expression SEMICOLON\n");}
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON {printf("IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON\n");}
    ;

Expression: Expression AND Expression {printf("Expression AND Expression\n");}
	| Expression LESS Expression {printf("Expression LESS Expression\n");}
	| Expression PLUS Expression {printf("Expression PLUS Expression\n");}
	| Expression MINUS Expression {printf("Expression MINUS Expression\n");}
	| Expression MULTIPLY Expression {printf("Expression MULTIPLY Expression\n");}
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET {printf("Expression LSQUAREBRACKET Expression RSQUAREBRACKET\n");}
    | Expression DOTLENGTH {printf("Expression DOTLENGTH\n");}
    | Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN {printf("Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN\n");}
    | INTLITERAL {printf("INTLITERAL\n");}
    | _TRUE {printf("_TRUE\n");}
    | _FALSE {printf("_FALSE\n");}
    | IDENTIFIER {printf("IDENTIFIER\n");}
    | THIS	{printf("THIS\n");}
    | NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET {printf("NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET\n");}
    | NEW IDENTIFIER LPAREN RPAREN {printf("NEW IDENTIFIER LPAREN RPAREN\n");}
    | NOT Expression {printf("NOT Expression\n");}
    | LPAREN Expression RPAREN {printf("LPAREN Expression RPAREN\n");}
    ;

/*
Operator: AND {printf("AND\n");}
	| LESS {printf("LESS\n");}
	| PLUS {printf("PLUS\n");}
	| MINUS {printf("MINUS\n");}
	| MULTIPLY {printf("MULTIPLY\n");}
	;
*/
ExpressionParamS: %empty
	| Expression AddittionalExpressionParamS {printf("Expression AddittionalExpressionParamS\n");}
	;

AddittionalExpressionParamS: %empty
	| AddittionalExpressionParamS AddittionalExpressionParam {printf("AddittionalExpressionParamS AddittionalExpressionParam\n");}
	;

AddittionalExpressionParam: COMMA Expression {printf("COMMA Expression\n");}
	;

/*
Expression: Expression PLUS Expression {printf("Expression Operator Expression\n");}
    | INTLITERAL {printf("INTLITERAL\n");}
    | IDENTIFIER {printf("IDENTIFIER\n");}
    ;


AdditionalExpressionS: %empty
	| AdditionalExpressionS AdditionalExpression
	;

AdditionalExpression: Operator Expression
	; 


Operator: PLUS {printf("PLUS\n");}
	;
*/
%%
