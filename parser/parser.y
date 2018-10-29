%{
#include <cstdio>
#include "parser.h"
%}

%locations
%verbose
%parse-param {void*& node}

%union {
	class IGoal* goal;
	class IClassDeclarationS* classDeclarationS;
	class IMainClass* mainClass;
	class IClassDeclaration* classDeclaration;
	class IExtension* extension;
	class IVarDeclarationS* varDeclarationS;
	class IVarDeclaration* varDeclaration;
	class IMethodDeclarationS* methodDeclarationS;
	class IMethodDeclaration* methodDeclaration;
	class IParams* params;
	class IAdditionalParamS* additionalParamS;
	class IAdditionalParam* additionalParam;
	class IType* type;
	class IStatementS* statementS;
	class IStatement* statement;
	class IExpression* expression;
	class IExpressionParamS* expressionParamS;
	class IAdditionalExpressionParamS* additionalExpressionParamS;
	class IAdditionalExpressionParam* additionalExpressionParam;
	class CTerminalIdentifier* terminalIdentifier;
	class CTerminalIntliteral* terminalIntliteral;
}

%token <terminalIdentifier> IDENTIFIER
%token IF ELSE WHILE
%token <terminalIntliteral> INTLITERAL
%token _TRUE _FALSE PUBLIC STATIC EXTENDS VOID MAIN RETURN NEW THIS PRINTLN DOTLENGTH STRING INT BOOLEAN CLASS LCURLYBRACE RCURLYBRACE LPAREN RPAREN LSQUAREBRACKET RSQUAREBRACKET SEMICOLON COMMA DOT EQUALS NOT LESS AND PLUS MINUS MULTIPLY

%left AND
%left LESS
%right NOT
%left PLUS MINUS
%left MULTIPLY
%left LSQUAREBRACKET
%left DOT DOTLENGTH

%type <goal> Goal
%type <classDeclarationS> ClassDeclarationS
%type <mainClass> MainClass
%type <classDeclaration> ClassDeclaration
%type <extension> Extension
%type <varDeclarationS> VarDeclarationS
%type <varDeclaration> VarDeclaration
%type <methodDeclarationS> MethodDeclarationS
%type <methodDeclaration> MethodDeclaration
%type <params> Params
%type <additionalParamS> AdditionalParamS
%type <additionalParam> AdditionalParam
%type <type> Type
%type <statementS> StatementS
%type <statement> Statement
%type <expression> Expression
%type <expressionParamS> ExpressionParamS
%type <additionalExpressionParamS> AdditionalExpressionParamS
%type <additionalExpressionParam> AdditionalExpressionParam

%%

Goal: MainClass ClassDeclarationS { PARSER_PROCESS_RULE( Goal, ); node = new CGoal($1, $2); $$ = (CGoal*)node;}
    ;

ClassDeclarationS: %empty { $$ = nullptr; }
	| ClassDeclarationS ClassDeclaration { PARSER_PROCESS_RULE( ClassDeclarationS, ); $$ = new CClassDeclarationS($1, $2);}
	;

MainClass: CLASS IDENTIFIER LCURLYBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LSQUAREBRACKET RSQUAREBRACKET IDENTIFIER RPAREN LCURLYBRACE StatementS RCURLYBRACE RCURLYBRACE { PARSER_PROCESS_RULE( MainClass, ); $$ = new CMainClass($2, $12, $15);}
    ;

ClassDeclaration: CLASS IDENTIFIER Extension LCURLYBRACE VarDeclarationS MethodDeclarationS RCURLYBRACE { PARSER_PROCESS_RULE( ClassDeclaration, ); $$ = new CClassDeclaration($2, $3, $5, $6);}
    ;

Extension: %empty { $$ = nullptr; }
	| EXTENDS IDENTIFIER { PARSER_PROCESS_RULE( Extension, ); $$ = new CExtension($2);}
	;

VarDeclarationS: %empty { $$ = nullptr; }
	| VarDeclarationS VarDeclaration { PARSER_PROCESS_RULE( VarDeclarationS, ); $$ = new CVarDeclarationS($1, $2);}
	;

VarDeclaration: Type IDENTIFIER SEMICOLON { PARSER_PROCESS_RULE( VarDeclaration, ); $$ = new CVarDeclaration($1, $2);}
    ;

MethodDeclarationS: %empty { $$ = nullptr; }
	| MethodDeclarationS MethodDeclaration { PARSER_PROCESS_RULE( MethodDeclarationS, ); $$ = new CMethodDeclarationS($1, $2);}
	;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE { PARSER_PROCESS_RULE( MethodDeclaration, ); $$ = new CMethodDeclaration($2, $3, $5, $8, $9, $11);}
    ;

Params: %empty { $$ = nullptr; }
	| Type IDENTIFIER AdditionalParamS { PARSER_PROCESS_RULE( Params, ); $$ = new CParams($1, $2, $3);}
	;

AdditionalParamS: %empty { $$ = nullptr; }
	| AdditionalParamS AdditionalParam { PARSER_PROCESS_RULE( AdditionalParamS, ); $$ = new CAdditionalParamS($1, $2);}
	;

AdditionalParam: COMMA Type IDENTIFIER { PARSER_PROCESS_RULE( AdditionalParam, ); $$ = new CAdditionalParam($2, $3);}
	;

Type: INT LSQUAREBRACKET RSQUAREBRACKET { PARSER_PROCESS_RULE( Type, INT LSQUAREBRACKET RSQUAREBRACKET ); $$ = new CIntArrayType();}
    | BOOLEAN { PARSER_PROCESS_RULE( Type, BOOLEAN ); $$ = new CBooleanType();}
    | INT { PARSER_PROCESS_RULE( Type, INT ); $$ = new CIntType();}
    | IDENTIFIER { PARSER_PROCESS_RULE( Type, IDENTIFIER ); $$ = new CCustomType($1);}
    ;

StatementS: %empty { $$ = nullptr; }
	| Statement StatementS { PARSER_PROCESS_RULE( StatementS, ); $$ = new CStatementS($1, $2);}
	;

Statement: LCURLYBRACE StatementS RCURLYBRACE { PARSER_PROCESS_RULE( Statement, LCURLYBRACE StatementS RCURLYBRACE ); $$ = new CCurlyBraceStatement($2);}
    | IF LPAREN Expression RPAREN Statement ELSE Statement { PARSER_PROCESS_RULE( Statement, IF LPAREN Expression RPAREN Statement ELSE Statement ); $$ = new CIfElseStatement($3, $5, $7);}
    | WHILE LPAREN Expression RPAREN Statement { PARSER_PROCESS_RULE( Statement, WHILE LPAREN Expression RPAREN Statement ); $$ = new CWhileStatement($3, $5);}
    | PRINTLN LPAREN Expression RPAREN SEMICOLON { PARSER_PROCESS_RULE( Statement, PRINTLN LPAREN Expression RPAREN SEMICOLON ); $$ = new CPrintlnStatement($3);}
    | IDENTIFIER EQUALS Expression SEMICOLON { PARSER_PROCESS_RULE( Statement, IDENTIFIER EQUALS Expression SEMICOLON ); $$ = new CVarAssignmentStatement($1, $3);}
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON { PARSER_PROCESS_RULE( Statement, IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON ); $$ = new CArrayAssignmentStatement($1, $3, $6);}
    ;

Expression: Expression AND Expression { PARSER_PROCESS_RULE( Expression, Expression AND Expression ); $$ = new CBinaryOpExpression($1, CBinaryOpExpression::AND, $3);}
	| Expression LESS Expression { PARSER_PROCESS_RULE( Expression, Expression LESS Expression ); $$ = new CBinaryOpExpression($1, CBinaryOpExpression::LESS, $3);}
	| Expression PLUS Expression { PARSER_PROCESS_RULE( Expression, Expression PLUS Expression ); $$ = new CBinaryOpExpression($1, CBinaryOpExpression::PLUS, $3);}
	| Expression MINUS Expression { PARSER_PROCESS_RULE( Expression, Expression MINUS Expression ); $$ = new CBinaryOpExpression($1, CBinaryOpExpression::MINUS, $3);}
	| Expression MULTIPLY Expression { PARSER_PROCESS_RULE( Expression, Expression MULTIPLY Expression ); $$ = new CBinaryOpExpression($1, CBinaryOpExpression::MULTIPLY, $3);}
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET { PARSER_PROCESS_RULE( Expression, Expression LSQUAREBRACKET Expression RSQUAREBRACKET ); $$ = new CSquarebracketsExpression($1, $3);}
    | Expression DOTLENGTH { PARSER_PROCESS_RULE( Expression, Expression DOTLENGTH ); $$ = new CLengthExpression($1);}
    | Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN { PARSER_PROCESS_RULE( Expression, Expression DOT IDENTIFIER LPAREN ExpressionParamS RPARE ); $$ = new CCallExpression($1, $3, $5);}
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

ExpressionParamS: %empty { $$ = nullptr; }
	| Expression AdditionalExpressionParamS { PARSER_PROCESS_RULE( ExpressionParamS, ); $$ = new CExpressionParamS($1, $2);}
	;

AdditionalExpressionParamS: %empty { $$ = nullptr; }
	| AdditionalExpressionParamS AdditionalExpressionParam { PARSER_PROCESS_RULE( AdditionalExpressionParamS, ); $$ = new CAdditionalExpressionParamS($1, $2);}
	;

AdditionalExpressionParam: COMMA Expression { PARSER_PROCESS_RULE( AdditionalExpressionParam, ); $$ = new CAdditionalExpressionParam($2);}
	;

%%
