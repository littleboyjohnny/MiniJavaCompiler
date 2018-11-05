%{
#include "../lexer/lexer.h"
#include "parser.h"

void yyerror( IAcceptable * & node, char const * msg );

void parserProcessRule( const char * left, const char * right );
%}

%locations
%verbose
%parse-param { IAcceptable * & node}

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

%%

Goal: MainClass ClassDeclarationS { parserProcessRule( "Goal", "CGoal" ); node = new CGoal( $1, $2 ); $$ = (CGoal*)node; }
    ;

ClassDeclarationS: %empty { $$ = nullptr; }
	| ClassDeclarationS ClassDeclaration { parserProcessRule( "ClassDeclarationS", "CClassDeclarationS" ); $$ = new CClassDeclarationS( $1, $2 );}
	;

MainClass: CLASS IDENTIFIER LCURLYBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LSQUAREBRACKET RSQUAREBRACKET IDENTIFIER RPAREN LCURLYBRACE StatementS RCURLYBRACE RCURLYBRACE { parserProcessRule( "MainClass", "CMainClass" ); $$ = new CMainClass( $2, $12, $15 ); }
    ;

ClassDeclaration: CLASS IDENTIFIER Extension LCURLYBRACE VarDeclarationS MethodDeclarationS RCURLYBRACE { parserProcessRule( "ClassDeclaration", "CClassDeclaration" ); $$ = new CClassDeclaration( $2, $3, $5, $6 ); }
    ;

Extension: %empty { $$ = nullptr; }
	| EXTENDS IDENTIFIER { parserProcessRule( "Extension", "CExtension" ); $$ = new CExtension( $2 ); }
	;

VarDeclarationS: %empty { $$ = nullptr; }
	| VarDeclarationS VarDeclaration { parserProcessRule( "VarDeclarationS", "CVarDeclarationS" ); $$ = new CVarDeclarationS( $1, $2 ); }
	;

VarDeclaration: Type IDENTIFIER SEMICOLON { parserProcessRule( "VarDeclaration", "CVarDeclaration" ); $$ = new CVarDeclaration( $1, $2 ); }
    ;

MethodDeclarationS: %empty { $$ = nullptr; }
	| MethodDeclarationS MethodDeclaration { parserProcessRule( "MethodDeclarationS", "CMethodDeclarationS" ); $$ = new CMethodDeclarationS( $1, $2 ); }
	;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN Params RPAREN LCURLYBRACE VarDeclarationS StatementS RETURN Expression SEMICOLON RCURLYBRACE { parserProcessRule( "MethodDeclaration", "CMethodDeclaration" ); $$ = new CMethodDeclaration( $2, $3, $5, $8, $9, $11 ); }
    ;

Params: %empty { $$ = nullptr; }
	| Param AdditionalParamS { parserProcessRule( "Params", "CParams" ); $$ = new CParams( $1, $2 ); }
	;

AdditionalParamS: %empty { $$ = nullptr; }
	| AdditionalParamS AdditionalParam { parserProcessRule( "AdditionalParamS", "CAdditionalParamS" ); $$ = new CAdditionalParamS( $1, $2 );}
	;

AdditionalParam: COMMA Param { parserProcessRule( "AdditionalParam", "CAdditionalParam" ); $$ = new CAdditionalParam( $2 );}
	;

Param: Type IDENTIFIER {parserProcessRule( "Param", "CParam" ); $$ = new CParam( $1, $2 );}
	;

Type: INT LSQUAREBRACKET RSQUAREBRACKET { parserProcessRule( "Type", "CIntArrayType" ); $$ = new CIntArrayType();}
    | BOOLEAN { parserProcessRule( "Type", "CBooleanType" ); $$ = new CBooleanType();}
    | INT { parserProcessRule( "Type", "CIntType" ); $$ = new CIntType();}
    | IDENTIFIER { parserProcessRule( "Type", "CCustomType" ); $$ = new CCustomType( $1 );}
    ;

StatementS: %empty { $$ = nullptr; }
	| Statement StatementS { parserProcessRule( "StatementS", "CStatementS" ); $$ = new CStatementS($1, $2);}
	;

Statement: LCURLYBRACE StatementS RCURLYBRACE { parserProcessRule( "Statement", "CCurlyBraceStatement" ); $$ = new CCurlyBraceStatement( $2 );}
    | IF LPAREN Expression RPAREN Statement ELSE Statement { parserProcessRule( "Statement", "CIfElseStatement" ); $$ = new CIfElseStatement( $3, $5, $7 );}
    | WHILE LPAREN Expression RPAREN Statement { parserProcessRule( "Statement", "CWhileStatement" ); $$ = new CWhileStatement( $3, $5 );}
    | PRINTLN LPAREN Expression RPAREN SEMICOLON { parserProcessRule( "Statement", "CPrintlnStatement" ); $$ = new CPrintlnStatement( $3 );}
    | IDENTIFIER EQUALS Expression SEMICOLON { parserProcessRule( "Statement", "CVarAssignmentStatement" ); $$ = new CVarAssignmentStatement( $1, $3 );}
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON { parserProcessRule( "Statement", "CArrayAssignmentStatement" ); $$ = new CArrayAssignmentStatement( $1, $3, $6 );}
    ;

Expression: Expression AND Expression { parserProcessRule( "Expression", "CBinaryOpExpression::AND" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::AND, $3 ); }
	| Expression LESS Expression { parserProcessRule( "Expression", "CBinaryOpExpression::LESS" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::LESS, $3 ); }
	| Expression PLUS Expression { parserProcessRule( "Expression", "CBinaryOpExpression::PLUS" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::PLUS, $3 ); }
	| Expression MINUS Expression { parserProcessRule( "Expression", "CBinaryOpExpression::MINUS" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::MINUS, $3 ); }
	| Expression MULTIPLY Expression { parserProcessRule( "Expression", "CBinaryOpExpression::MULTIPLY" ); $$ = new CBinaryOpExpression( $1, CBinaryOpExpression::MULTIPLY, $3 ); }
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET { parserProcessRule( "Expression", "CSquarebracketsExpression" ); $$ = new CSquarebracketsExpression( $1, $3 ); }
    | Expression DOTLENGTH { parserProcessRule( "Expression", "CLengthExpression" ); $$ = new CLengthExpression( $1 ); }
    | Expression DOT IDENTIFIER LPAREN ExpressionParamS RPAREN { parserProcessRule( "Expression", "CCallExpression" ); $$ = new CCallExpression( $1, $3, $5 ); }
    | INTLITERAL { parserProcessRule( "Expression", "CIntliteralExpression" ); $$ = new CIntliteralExpression( $1 ); }
    | _TRUE { parserProcessRule( "Expression", "CTrueExpression" ); $$ = new CTrueExpression(); }
    | _FALSE { parserProcessRule( "Expression", "CFalseExpression" ); $$ = new CFalseExpression(); }
    | IDENTIFIER { parserProcessRule( "Expression", "CIdentifierExpression" ); $$ = new CIdentifierExpression( $1 ); }
    | THIS	{ parserProcessRule( "Expression", "CThisExpression" ); $$ = new CThisExpression(); }
    | NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET { parserProcessRule( "Expression", "CNewArrayExpression" ); $$ = new CNewArrayExpression( $4 ); }
    | NEW IDENTIFIER LPAREN RPAREN { parserProcessRule( "Expression", "CNewIdentifierExpression" ); $$ = new CNewIdentifierExpression( $2 ); }
    | NOT Expression { parserProcessRule( "Expression", "CNotExpression" ); $$ = new CNotExpression( $2 ); }
    | LPAREN Expression RPAREN { parserProcessRule( "Expression", "CParensExpression" ); $$ = new CParensExpression( $2 ); }
    ;

ExpressionParamS: %empty { $$ = nullptr; }
	| Expression AdditionalExpressionParamS { parserProcessRule( "ExpressionParamS", "CExpressionParamS" ); $$ = new CExpressionParamS( $1, $2 ); }
	;

AdditionalExpressionParamS: %empty { $$ = nullptr; }
	| AdditionalExpressionParamS AdditionalExpressionParam { parserProcessRule( "AdditionalExpressionParamS", "CAdditionalExpressionParamS" ); $$ = new CAdditionalExpressionParamS( $1, $2 ); }
	;

AdditionalExpressionParam: COMMA Expression { parserProcessRule( "AdditionalExpressionParam", "CAdditionalExpressionParam" ); $$ = new CAdditionalExpressionParam( $2 ); }
	;

%%
