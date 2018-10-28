%{
#include <stdio.h>
#include "parser.h"
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

Goal: MainClass ClassDeclarationS { PARSER_PROCESS_RULE( Goal, ); $$ = new CGoal($1, $2);}
    ;

ClassDeclarationS: %empty
	| ClassDeclarationS ClassDeclaration { PARSER_PROCESS_RULE( ClassDeclarationS, ); $$ = new CClassDeclarationS($1, $2);}
	;

MainClass: CLASS IDENTIFIER LCURLYBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LSQUAREBRACKET RSQUAREBRACKET IDENTIFIER RPAREN LCURLYBRACE StatementS RCURLYBRACE RCURLYBRACE { PARSER_PROCESS_RULE( MainClass, ); $$ = new CMainClass($2, $12, $15);}
    ;

ClassDeclaration: CLASS IDENTIFIER Extension LCURLYBRACE VarDeclarationS MethodDeclarationS RCURLYBRACE { PARSER_PROCESS_RULE( ClassDeclaration, ); $$ = new CClassDeclaration($2, $3, $5, $6);}
    ;

Extension: %empty
	| EXTENDS IDENTIFIER { PARSER_PROCESS_RULE( Extension, ); $$ = new CExtension($2);}
	;

VarDeclarationS: %empty
	| VarDeclarationS VarDeclaration { PARSER_PROCESS_RULE( VarDeclarationS, ); $$ = new CVarDeclarationS($1, $2);}
	;

VarDeclaration: Type IDENTIFIER SEMICOLON { PARSER_PROCESS_RULE( VarDeclaration, ); $$ = new CVarDeclaration($1, $2);}
    ;

MethodDeclarationS: %empty
	| MethodDeclarationS MethodDeclaration { PARSER_PROCESS_RULE( MethodDeclarationS, ); $$ = new CMethodDeclarationS($1, $2);}
	;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE { PARSER_PROCESS_RULE( MethodDeclaration, ); $$ = new CMethodDeclarationS($2, $3, $5, $8, $9, $11);}
    ;

Params: %empty
	| Type IDENTIFIER AdditionalParamS { PARSER_PROCESS_RULE( Params, ); $$ = new CParams($1, $2, $3);}
	;

AdditionalParamS: %empty
	| AdditionalParamS AdditionalParam { PARSER_PROCESS_RULE( AdditionalParamS, ); $$ = new CAdditionalParamS($1, $2);}
	;

AdditionalParam: COMMA Type IDENTIFIER { PARSER_PROCESS_RULE( AdditionalParam, ); $$ = new CAdditionalParamS($2, $3);}
	;

Type: INT LSQUAREBRACKET RSQUAREBRACKET { PARSER_PROCESS_RULE( Type, INT LSQUAREBRACKET RSQUAREBRACKET ); $$ = new CIntArrayType();}
    | BOOLEAN { PARSER_PROCESS_RULE( Type, BOOLEAN ); $$ = new CBooleanType();}
    | INT { PARSER_PROCESS_RULE( Type, INT ); $$ = new CIntType();}
    | IDENTIFIER { PARSER_PROCESS_RULE( Type, IDENTIFIER ); $$ = new CCustomType($1);}
    ;

StatementS: %empty
	| Statement StatementS { PARSER_PROCESS_RULE( StatementS, ); $$ = new CStatementS($1, $2);}
	;

Statement: LCURLYBRACE StatementS RCURLYBRACE { PARSER_PROCESS_RULE( Statement, LCURLYBRACE StatementS RCURLYBRACE ); $$ = new CCurlyBraceStatement($2);}
    | IF LPAREN Expression RPAREN Statement ELSE Statement { PARSER_PROCESS_RULE( Statement, IF LPAREN Expression RPAREN Statement ELSE Statement ); $$ = new CIfElseStatement($3, $5, $7);}
    | WHILE LPAREN Expression RPAREN Statement { PARSER_PROCESS_RULE( Statement, WHILE LPAREN Expression RPAREN Statement ); $$ = new CWhileStatement($3, $5);}
    | PRINTLN LPAREN Expression RPAREN SEMICOLON { PARSER_PROCESS_RULE( Statement, PRINTLN LPAREN Expression RPAREN SEMICOLON ); $$ = new CPrintlnStatement($3);}
    | IDENTIFIER EQUALS Expression SEMICOLON { PARSER_PROCESS_RULE( Statement, IDENTIFIER EQUALS Expression SEMICOLON ); $$ = new CVarAssignmentStatement($1, $3);}
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON { PARSER_PROCESS_RULE( Statement, IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON ); $$ = new CArrayAssignmentStatement($1, $3, $6);}
    ;

Expression: Expression AND Expression { PARSER_PROCESS_RULE( Expression, Expression AND Expression ); $$ = new CAndExpression($1, $3);}
	| Expression LESS Expression { PARSER_PROCESS_RULE( Expression, Expression LESS Expression ); $$ = new CLessExpression($1, $3);}
	| Expression PLUS Expression { PARSER_PROCESS_RULE( Expression, Expression PLUS Expression ); $$ = new CPlusExpression($1, $3);}
	| Expression MINUS Expression { PARSER_PROCESS_RULE( Expression, Expression MINUS Expression ); $$ = new CMinusExpression($1, $3);}
	| Expression MULTIPLY Expression { PARSER_PROCESS_RULE( Expression, Expression MULTIPLY Expression ); $$ = new CMultiplyExpression($1, $3);}
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET { PARSER_PROCESS_RULE( Expression, Expression LSQUAREBRACKET Expression RSQUAREBRACKET ); $$ = new CSquarebracketsExpression($1, $3);}
    | Expression DOTLENGTH { PARSER_PROCESS_RULE( Expression, Expression DOTLENGTH ); $$ = new CLengthExpression($1);}
    | Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN { PARSER_PROCESS_RULE( Expression, Expression DOT IDENTIFIER LPAREN ExpressionParamS RPARE ); $$ = new CDotExpression($1, $3, $5);}
    | INTLITERAL { PARSER_PROCESS_RULE( Expression, INTLITERAL ); $$ = new CIntliteralExpression($1);}
    | _TRUE { PARSER_PROCESS_RULE( Expression, _TRUE ); $$ = new CTrueExpression();}
    | _FALSE { PARSER_PROCESS_RULE( Expression, _FALSE ); $$ = new CFalseExpression();}
    | IDENTIFIER { PARSER_PROCESS_RULE( Expression, IDENTIFIER ); $$ = new CIdentifierExpression($1);}
    | THIS	{ PARSER_PROCESS_RULE( Expression, THIS ); $$ = new CThisExpression();}
    | NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET { PARSER_PROCESS_RULE( Expression, NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET ); $$ = new CNewArrayExpression($4);}
    | NEW IDENTIFIER LPAREN RPAREN { PARSER_PROCESS_RULE( Expression, NEW IDENTIFIER LPAREN RPAREN ); $$ = new CNewIdentifierExpression($2);}
    | NOT Expression { PARSER_PROCESS_RULE( Expression, NOT Expression ); $$ = new CNotExpression($2);}
    | LPAREN Expression RPAREN { PARSER_PROCESS_RULE( Expression, LPAREN Expression RPAREN ); $$ = new CParensExpression($2);}
    ;

ExpressionParamS: %empty
	| Expression AddittionalExpressionParamS { PARSER_PROCESS_RULE( ExpressionParamS, ); $$ = new CExpressionParamS($1, $2);}
	;

AddittionalExpressionParamS: %empty
	| AddittionalExpressionParamS AddittionalExpressionParam { PARSER_PROCESS_RULE( AddittionalExpressionParamS, ); $$ = new CAddittionalExpressionParamS($1, $2);}
	;

AddittionalExpressionParam: COMMA Expression { PARSER_PROCESS_RULE( AddittionalExpressionParam, ); $$ = new CAdditionalExpressionParam($2);}
	;

%%
