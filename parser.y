%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
        fprintf(stderr,"ошибка: %s\n",str);
}

int main() {
	yyparse();
}


%}

%locations

%union {
	int intVal;
	char *stringVal;
}

%token <stringVal> IDENTIFIER 
%token IF ELSE WHILE
%token <intVal> INTLITERAL
%token _TRUE _FALSE PUBLIC STATIC VOID MAIN NEW THIS TYPE CLASS LCURLYBRACE RCURLYBRACE LPAREN RPAREN LSQUAREBRACKET RSQUAREBRACKET SEMICOLON COMMA DOT EQUALS NOT LESS AND PLUS MINUS MULTIPLY

%%

commands: /*EMPTY*/
	| commands command 
	;

command: boolliteral
	| sys 
	| brace
	| type
	| booloperator
	| arithoperator
	| MAIN {printf("parserMAIN(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| IDENTIFIER {printf("parserIDENTIFIER(val:%s, loc:%d, %d) ", yylval.stringVal, @1.first_line, @1.first_column);}
	| INTLITERAL {printf("parserINTLITERAL(val:%d, loc:%d, %d) ", yylval.intVal, @1.first_line, @1.first_column);}
	| COMMA {printf("parserCOMMA(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| DOT {printf("parserDOT(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| SEMICOLON {printf("parserSEMICOLON(loc:%d, %d) \n", @1.first_line, @1.first_column);}
	;

boolliteral: _TRUE {printf("parser_TRUE(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| _FALSE {printf("parser_FALSE(loc:%d, %d) ", @1.first_line, @1.first_column);}
	;

sys: PUBLIC {printf("parserPUBLIC(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| STATIC {printf("parserSTATIC(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| CLASS {printf("parserCLASS(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| IF {printf("parserIF(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| ELSE {printf("parserELSE(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| WHILE {printf("parserWHILE(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| NEW {printf("parserNEW(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| THIS {printf("parserTHIS(loc:%d, %d) ", @1.first_line, @1.first_column);}
	;

brace: LCURLYBRACE {printf("parserLCURLYBRACE(loc:%d, %d) \n", @1.first_line, @1.first_column);}
	| RCURLYBRACE {printf("\nparserRCURLYBRACE(loc:%d, %d) \n", @1.first_line, @1.first_column);}
	| LPAREN {printf("parserLPAREN(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| RPAREN {printf("parserRPAREN(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| LSQUAREBRACKET {printf("parserLSQUAREBRACKET(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| RSQUAREBRACKET {printf("parserRSQUAREBRACKET(loc:%d, %d) ", @1.first_line, @1.first_column);}
	;

type: TYPE {printf("parserTYPE(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| VOID {printf("parserVOID(loc:%d, %d) ", @1.first_line, @1.first_column);}
	;

booloperator: NOT {printf("parserNOT(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| LESS {printf("parserLESS(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| AND {printf("parserAND(loc:%d, %d) ", @1.first_line, @1.first_column);}
	;

arithoperator: EQUALS {printf("parserEQUALS(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| PLUS {printf("parserPLUS(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| MINUS {printf("parserMINUS(loc:%d, %d) ", @1.first_line, @1.first_column);}
	| MULTIPLY {printf("parserMULTIPLY(loc:%d, %d) ", @1.first_line, @1.first_column);}
	;

Goal: MainClass ( ClassDeclaration )* <EOF>
    ;

MainClass: CLASS IDENTIFIER LCURLYBRACE PUBLIC STATIC VOID MAIN LPAREN STRING LSQUAREBRACKET RSQUAREBRACKET IDENTIFIER RPAREN LCURLYBRACE STATEMENT RCURLYBRACE RCURLYBRACE
    ;

ClassDeclaration: CLASS IDENTIFIER ( EXTENDS IDENTIFIER )? LCURLYBRACE ( VarDeclaration )* ( MethodDeclaration )* RCURLYBRACE
    ;

VarDeclaration: Type LCURLYBRACE SEMICOLON
    ;

MethodDeclaration: PUBLIC Type IDENTIFIER LPAREN ( Type IDENTIFIER ( COMMA Type IDENTIFIER )* )? RPAREN LCURLYBRACE ( VarDeclaration )*( Statement )* RETURN Expression SEMICOLON RCURLYBRACE
    ;

Type: "int" "[" "]"
    | "boolean"
    | "int"
    | IDENTIFIER
    ;

Statement: LCURLYBRACE ( Statement )* RCURLYBRACE
    | IF LPAREN Expression RPAREN Statement ELSE Statement
    | WHILE LPAREN Expression RPAREN Statement
    | "System.out.println" LPAREN Expression RPAREN SEMICOLON
    | IDENTIFIER EQUALS Expression SEMICOLON
    | IDENTIFIER LSQUAREBRACKET Expression RSQUAREBRACKET EQUALS Expression SEMICOLON
    ;

Expressio: Expression ( AND | LESS | PLUS | MINUS | MULTIPLY ) Expression
    | Expression LSQUAREBRACKET Expression RSQUAREBRACKET
    | Expression DOT "length"
    | Expression DOT IDENTIFIER LPAREN ( Expression ( COMMA Expression )* )? RPAREN
    | <INTEGER_LITERAL>
    | _TRUE
    | _FALSE
    | IDENTIFIER
    | THIS
    | NEW INT LSQUAREBRACKET Expression RSQUAREBRACKET
    | NEW Identifier LPAREN RPAREN
    | NOT Expression
    | LPAREN Expression RPAREN
    ;
%%
