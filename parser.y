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

%union {
	int intVal;
	char *stringVal;
}

%token <stringVal> IDENTIFIER 
%token IF ELSE WHILE
%token <intVal> INTLITERAL
%token _TRUE _FALSE PUBLIC STATIC EXTENDS VOID MAIN RETURN NEW THIS PRINTLN DOTLENGTH STRING INT BOOLEAN CLASS LCURLYBRACE RCURLYBRACE LPAREN RPAREN LSQUAREBRACKET RSQUAREBRACKET SEMICOLON COMMA DOT EQUALS NOT LESS AND PLUS MINUS MULTIPLY

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
	| EXTENDS IDENTIFIER
	;

VarDeclarationS: %empty
	| VarDeclarationS VarDeclaration {printf("VarDeclarationS\n");}
	;

VarDeclaration: Type IDENTIFIER SEMICOLON
    ;

MethodDeclarationS: %empty
	| MethodDeclarationS MethodDeclaration
	;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE
    ;

Params: %empty
	| Type IDENTIFIER AdditionalParamS
	;

AdditionalParamS: %empty
	| AdditionalParamS AdditionalParam
	;

AdditionalParam: COMMA Type IDENTIFIER
	;

Type: INT LSQUAREBRACKET RSQUAREBRACKET //"int" "[" "]"
    | BOOLEAN
    | INT
    | IDENTIFIER
    ;

StatementS: %empty
	| StatementS Statement {printf("StatementS\n");}
	;

Statement: LCURLYBRACE StatementS RCURLYBRACE
    | IF LPAREN Expression RPAREN Statement ELSE Statement
    | WHILE LPAREN Expression RPAREN Statement
    | PRINTLN LPAREN Expression RPAREN SEMICOLON
    | IDENTIFIER EQUALS Expression SEMICOLON {printf("Equals\n");}
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON
    ;

Expression: Expression Operator Expression
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET
    | Expression DOTLENGTH
    | Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN {printf("Dot-chtoto\n");}
    | INTLITERAL
    | _TRUE
    | _FALSE
    | IDENTIFIER
    | THIS	{printf("FindThis\n");}
    | NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET
    | NEW IDENTIFIER LPAREN RPAREN
    | NOT Expression
    | LPAREN Expression RPAREN
    ;

Operator: AND 
	| LESS 
	| PLUS 
	| MINUS 
	| MULTIPLY
	;

ExpressionParamS: %empty
	| Expression AddittionalExpressionParamS
	;

AddittionalExpressionParamS: %empty
	| AddittionalExpressionParamS AddittionalExpressionParam
	;

AddittionalExpressionParam: COMMA Expression
	;

%%
