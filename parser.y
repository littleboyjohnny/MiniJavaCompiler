%{
#include <stdio.h>
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

Goal: MainClass ClassDeclarationS { PARSER_PROCESS_RULE( Goal, ); }
    ;

ClassDeclarationS: %empty
	| ClassDeclarationS ClassDeclaration { PARSER_PROCESS_RULE( ClassDeclarationS, ); }
	;

MainClass: CLASS IDENTIFIER LCURLYBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LSQUAREBRACKET RSQUAREBRACKET IDENTIFIER RPAREN LCURLYBRACE StatementS RCURLYBRACE RCURLYBRACE { PARSER_PROCESS_RULE( MainClass, ); }
    ;

ClassDeclaration: CLASS IDENTIFIER Extension LCURLYBRACE VarDeclarationS MethodDeclarationS RCURLYBRACE { PARSER_PROCESS_RULE( ClassDeclaration, ); }
    ;

Extension: %empty
	| EXTENDS IDENTIFIER { PARSER_PROCESS_RULE( Extension, ); }
	;

VarDeclarationS: %empty
	| VarDeclarationS VarDeclaration { PARSER_PROCESS_RULE( VarDeclarationS, ); }
	;

VarDeclaration: Type IDENTIFIER SEMICOLON { PARSER_PROCESS_RULE( VarDeclaration, ); }
    ;

MethodDeclarationS: %empty
	| MethodDeclarationS MethodDeclaration { PARSER_PROCESS_RULE( MethodDeclarationS, ); }
	;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE { PARSER_PROCESS_RULE( MethodDeclaration, ); }
    ;

Params: %empty
	| Type IDENTIFIER AdditionalParamS { PARSER_PROCESS_RULE( Params, ); }
	;

AdditionalParamS: %empty
	| AdditionalParamS AdditionalParam { PARSER_PROCESS_RULE( AdditionalParamS, ); }
	;

AdditionalParam: COMMA Type IDENTIFIER { PARSER_PROCESS_RULE( AdditionalParam, ); }
	;

Type: INT LSQUAREBRACKET RSQUAREBRACKET { PARSER_PROCESS_RULE( Type, INT LSQUAREBRACKET RSQUAREBRACKET ); }
    | BOOLEAN { PARSER_PROCESS_RULE( Type, BOOLEAN ); }
    | INT { PARSER_PROCESS_RULE( Type, INT ); }
    | IDENTIFIER { PARSER_PROCESS_RULE( Type, IDENTIFIER ); }
    ;

StatementS: %empty
	| Statement StatementS { PARSER_PROCESS_RULE( StatementS, ); }
	;

Statement: LCURLYBRACE StatementS RCURLYBRACE { PARSER_PROCESS_RULE( Statement, LCURLYBRACE StatementS RCURLYBRACE ); }
    | IF LPAREN Expression RPAREN Statement ELSE Statement { PARSER_PROCESS_RULE( Statement, IF LPAREN Expression RPAREN Statement ELSE Statement ); }
    | WHILE LPAREN Expression RPAREN Statement { PARSER_PROCESS_RULE( Statement, WHILE LPAREN Expression RPAREN Statement ); }
    | PRINTLN LPAREN Expression RPAREN SEMICOLON { PARSER_PROCESS_RULE( Statement, PRINTLN LPAREN Expression RPAREN SEMICOLON ); }
    | IDENTIFIER EQUALS Expression SEMICOLON { PARSER_PROCESS_RULE( Statement, IDENTIFIER EQUALS Expression SEMICOLON ); }
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON { PARSER_PROCESS_RULE( Statement, IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON ); }
    ;

Expression: Expression AND Expression { PARSER_PROCESS_RULE( Expression, Expression AND Expression ); }
	| Expression LESS Expression { PARSER_PROCESS_RULE( Expression, Expression LESS Expression ); }
	| Expression PLUS Expression { PARSER_PROCESS_RULE( Expression, Expression PLUS Expression ); }
	| Expression MINUS Expression { PARSER_PROCESS_RULE( Expression, Expression MINUS Expression ); }
	| Expression MULTIPLY Expression { PARSER_PROCESS_RULE( Expression, Expression MULTIPLY Expression ); }
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET { PARSER_PROCESS_RULE( Expression, Expression LSQUAREBRACKET Expression RSQUAREBRACKET ); }
    | Expression DOTLENGTH { PARSER_PROCESS_RULE( Expression, Expression DOTLENGTH ); }
    | Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN { PARSER_PROCESS_RULE( Expression, Expression DOT IDENTIFIER LPAREN ExpressionParamS RPARE ); }
    | INTLITERAL { PARSER_PROCESS_RULE( Expression, INTLITERAL ); }
    | _TRUE { PARSER_PROCESS_RULE( Expression, _TRUE ); }
    | _FALSE { PARSER_PROCESS_RULE( Expression, _FALSE ); }
    | IDENTIFIER { PARSER_PROCESS_RULE( Expression, IDENTIFIER ); }
    | THIS	{ PARSER_PROCESS_RULE( Expression, THIS ); }
    | NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET { PARSER_PROCESS_RULE( Expression, NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET ); }
    | NEW IDENTIFIER LPAREN RPAREN { PARSER_PROCESS_RULE( Expression, NEW IDENTIFIER LPAREN RPAREN ); }
    | NOT Expression { PARSER_PROCESS_RULE( Expression, NOT Expression ); }
    | LPAREN Expression RPAREN { PARSER_PROCESS_RULE( Expression, LPAREN Expression RPAREN ); }
    ;

ExpressionParamS: %empty
	| Expression AddittionalExpressionParamS { PARSER_PROCESS_RULE( ExpressionParamS, ); }
	;

AddittionalExpressionParamS: %empty
	| AddittionalExpressionParamS AddittionalExpressionParam { PARSER_PROCESS_RULE( AddittionalExpressionParamS, ); }
	;

AddittionalExpressionParam: COMMA Expression { PARSER_PROCESS_RULE( AddittionalExpressionParam, ); }
	;

%%
