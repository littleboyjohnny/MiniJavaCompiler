%{
#include "../lexer/lexer.h"
#include "parser.h"

void yyerror( IAcceptable * & node, FILE * fout, char const * msg );

void parserProcessRule( FILE * fout, const char * left, const char * right );
%}

%define parse.error verbose
%locations
%verbose
%parse-param { IAcceptable * & node }
%parse-param { FILE * fout }

%union {
    class CTerminalIdentifier* terminalIdentifier;
	class CTerminalIntliteral* terminalIntliteral;

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
	class IParam* param;
	class IType* type;
	class IStatementS* statementS;
	class IStatement* statement;
	class IExpression* expression;
	class IExpressionParamS* expressionParamS;
	class IAdditionalExpressionParamS* additionalExpressionParamS;
	class IAdditionalExpressionParam* additionalExpressionParam;
}

%token <terminalIdentifier> IDENTIFIER
%token <terminalIntliteral> INTLITERAL
%token IF ELSE WHILE _TRUE _FALSE PUBLIC STATIC EXTENDS VOID MAIN RETURN NEW THIS PRINTLN DOTLENGTH STRING INT BOOLEAN CLASS LCURLYBRACE RCURLYBRACE LPAREN RPAREN LSQUAREBRACKET RSQUAREBRACKET SEMICOLON COMMA DOT EQUALS NOT LESS AND PLUS MINUS MULTIPLY

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
%type <param> Param
%type <type> Type
%type <statementS> StatementS
%type <statement> Statement
%type <expression> Expression
%type <expressionParamS> ExpressionParamS
%type <additionalExpressionParamS> AdditionalExpressionParamS
%type <additionalExpressionParam> AdditionalExpressionParam

%destructor { } <goal>
%destructor { delete $$; } <*>

%%

Goal: MainClass ClassDeclarationS { parserProcessRule( fout, "Goal", "CGoal" ); node = new CGoal( $1, $2 ); $$ = (CGoal*)node; }
    ;

ClassDeclarationS: %empty { $$ = nullptr; }
	| ClassDeclarationS ClassDeclaration { parserProcessRule( fout, "ClassDeclarationS", "CClassDeclarationS" ); $$ = new CClassDeclarationS( $1, $2 );}
	;

MainClass: CLASS IDENTIFIER LCURLYBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LSQUAREBRACKET RSQUAREBRACKET IDENTIFIER RPAREN LCURLYBRACE StatementS RCURLYBRACE RCURLYBRACE { parserProcessRule( fout, "MainClass", "CMainClass" ); $$ = new CMainClass( $2, $12, $15 ); }
    ;

ClassDeclaration: CLASS IDENTIFIER Extension LCURLYBRACE VarDeclarationS MethodDeclarationS RCURLYBRACE { parserProcessRule( fout, "ClassDeclaration", "CClassDeclaration" ); $$ = new CClassDeclaration( $2, $3, $5, $6 ); }
    ;

Extension: %empty { $$ = nullptr; }
	| EXTENDS IDENTIFIER { parserProcessRule( fout, "Extension", "CExtension" ); $$ = new CExtension( $2 ); }
	;

VarDeclarationS: %empty { $$ = nullptr; }
	| VarDeclarationS VarDeclaration { parserProcessRule( fout, "VarDeclarationS", "CVarDeclarationS" ); $$ = new CVarDeclarationS( $1, $2 ); }
	;

VarDeclaration: Type IDENTIFIER SEMICOLON { parserProcessRule( fout, "VarDeclaration", "CVarDeclaration" ); $$ = new CVarDeclaration( $1, $2 ); }
    | Type error SEMICOLON   { yyerrok; }
    ;

MethodDeclarationS: %empty { $$ = nullptr; }
	| MethodDeclarationS MethodDeclaration { parserProcessRule( fout, "MethodDeclarationS", "CMethodDeclarationS" ); $$ = new CMethodDeclarationS( $1, $2 ); }
	;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE { parserProcessRule( fout, "MethodDeclaration", "CMethodDeclaration" ); $$ = new CMethodDeclaration( $2, $3, $5, $8, $9, $11 ); }
    | PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS error RCURLYBRACE { yyerrok; }
    ;

Params: %empty { $$ = nullptr; }
	| Param AdditionalParamS { parserProcessRule( fout, "Params", "CParams" ); $$ = new CParams( $1, $2 ); }
	;

AdditionalParamS: %empty { $$ = nullptr; }
	| AdditionalParamS AdditionalParam { parserProcessRule( fout, "AdditionalParamS", "CAdditionalParamS" ); $$ = new CAdditionalParamS( $1, $2 );}
	;

AdditionalParam: COMMA Param { parserProcessRule( fout, "AdditionalParam", "CAdditionalParam" ); $$ = new CAdditionalParam( $2 );}
    | COMMA error
	;

Param: Type IDENTIFIER {parserProcessRule( fout, "Param", "CParam" ); $$ = new CParam( $1, $2 );}
	;

Type: INT LSQUAREBRACKET RSQUAREBRACKET { parserProcessRule( fout, "Type", "CIntArrayType" ); $$ = new CIntArrayType();}
    | BOOLEAN { parserProcessRule( fout, "Type", "CBooleanType" ); $$ = new CBooleanType();}
    | INT { parserProcessRule( fout, "Type", "CIntType" ); $$ = new CIntType();}
    | IDENTIFIER { parserProcessRule( fout, "Type", "CCustomType" ); $$ = new CCustomType( $1 );}
    ;

StatementS: %empty { $$ = nullptr; }
	| Statement StatementS { parserProcessRule( fout, "StatementS", "CStatementS" ); $$ = new CStatementS($1, $2);}
	;

Statement: LCURLYBRACE StatementS RCURLYBRACE { parserProcessRule( fout, "Statement", "CCurlyBraceStatement" ); $$ = new CCurlyBraceStatement( $2 );}
    | IF LPAREN Expression RPAREN Statement ELSE Statement { parserProcessRule( fout, "Statement", "CIfElseStatement" ); $$ = new CIfElseStatement( $3, $5, $7 );}
    | WHILE LPAREN Expression RPAREN Statement { parserProcessRule( fout, "Statement", "CWhileStatement" ); $$ = new CWhileStatement( $3, $5 );}
    | PRINTLN LPAREN Expression RPAREN SEMICOLON { parserProcessRule( fout, "Statement", "CPrintlnStatement" ); $$ = new CPrintlnStatement( $3 );}
    | IDENTIFIER EQUALS Expression SEMICOLON { parserProcessRule( fout, "Statement", "CVarAssignmentStatement" ); $$ = new CVarAssignmentStatement( $1, $3 );}
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON { parserProcessRule( fout, "Statement", "CArrayAssignmentStatement" ); $$ = new CArrayAssignmentStatement( $1, $3, $6 );}
    | LCURLYBRACE error RCURLYBRACE { yyerrok; }
    | IF LPAREN error RPAREN Statement ELSE Statement   { yyerrok; }
    | WHILE LPAREN error RPAREN Statement   { yyerrok; }
    | error SEMICOLON   { yyerrok; }
    ;

Expression: Expression AND Expression { parserProcessRule( fout, "Expression", "CBinaryOpExpression::AND" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::AND, $3 ); }
	| Expression LESS Expression { parserProcessRule( fout, "Expression", "CBinaryOpExpression::LESS" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::LESS, $3 ); }
	| Expression PLUS Expression { parserProcessRule( fout, "Expression", "CBinaryOpExpression::PLUS" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::PLUS, $3 ); }
	| Expression MINUS Expression { parserProcessRule( fout, "Expression", "CBinaryOpExpression::MINUS" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::MINUS, $3 ); }
	| Expression MULTIPLY Expression { parserProcessRule( fout, "Expression", "CBinaryOpExpression::MULTIPLY" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::MULTIPLY, $3 ); }
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET { parserProcessRule( fout, "Expression", "CSquarebracketsExpression" ); $$ = new CSquarebracketsExpression( $1, $3 ); }
    | Expression DOTLENGTH { parserProcessRule( fout, "Expression", "CLengthExpression" ); $$ = new CLengthExpression( $1 ); }
    | Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN { parserProcessRule( fout, "Expression", "CCallExpression" ); $$ = new CCallExpression( $1, $3, $5 ); }
    | INTLITERAL { parserProcessRule( fout, "Expression", "CIntliteralExpression" ); $$ = new CIntliteralExpression( $1 ); }
    | _TRUE { parserProcessRule( fout, "Expression", "CTrueExpression" ); $$ = new CTrueExpression(); }
    | _FALSE { parserProcessRule( fout, "Expression", "CFalseExpression" ); $$ = new CFalseExpression(); }
    | IDENTIFIER { parserProcessRule( fout, "Expression", "CIdentifierExpression" ); $$ = new CIdentifierExpression( $1 ); }
    | THIS	{ parserProcessRule( fout, "Expression", "CThisExpression" ); $$ = new CThisExpression(); }
    | NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET { parserProcessRule( fout, "Expression", "CNewArrayExpression" ); $$ = new CNewArrayExpression( $4 ); }
    | NEW IDENTIFIER LPAREN RPAREN { parserProcessRule( fout, "Expression", "CNewIdentifierExpression" ); $$ = new CNewIdentifierExpression( $2 ); }
    | NOT Expression { parserProcessRule( fout, "Expression", "CNotExpression" ); $$ = new CNotExpression( $2 ); }
    | LPAREN Expression RPAREN { parserProcessRule( fout, "Expression", "CParensExpression" ); $$ = new CParensExpression( $2 ); }
    ;

ExpressionParamS: %empty { $$ = nullptr; }
	| Expression AdditionalExpressionParamS { parserProcessRule( fout, "ExpressionParamS", "CExpressionParamS" ); $$ = new CExpressionParamS( $1, $2 ); }
	;

AdditionalExpressionParamS: %empty { $$ = nullptr; }
	| AdditionalExpressionParamS AdditionalExpressionParam { parserProcessRule( fout, "AdditionalExpressionParamS", "CAdditionalExpressionParamS" ); $$ = new CAdditionalExpressionParamS( $1, $2 ); }
	;

AdditionalExpressionParam: COMMA Expression { parserProcessRule( fout, "AdditionalExpressionParam", "CAdditionalExpressionParam" ); $$ = new CAdditionalExpressionParam( $2 ); }
    | COMMA error   {yyerrok;}
	;

%%
