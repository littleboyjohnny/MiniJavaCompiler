%{
#include <stdio.h>
#include <string.h>

/*
#define YYLLOC_DEFAULT(Current, Rhs, N)	\
	Current.first_line   = Rhs[N].first_line; \
	Current.first_column = Rhs[N].first_column; \
	Current.last_line   = Rhs[N].last_line;	\
	Current.last_column = Rhs[N].last_column;
*/
void yyerror(const char *str)
{
        fprintf(stderr,"ошибка: %s\n",str);
}

int main() {
	yyparse();
}


%}

%locations

%token IDENTIFIER IF ELSE WHILE INTLITERAL _TRUE _FALSE PUBLIC STATIC VOID MAIN NEW THIS TYPE CLASS LCURLYBRACE RCURLYBRACE LPAREN RPAREN LSQUAREBRACKET RSQUAREBRACKET SEMICOLON COMMA DOT EQUALS NOT LESS AND PLUS MINUS MULTIPLY

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
	| MAIN {printf("parserMAIN ");}
	| IDENTIFIER {printf("parserIDENTIFIER(val:%s, loc:%d, %d) ", yylval, @$.first_line, @$.first_column);}
	| INTLITERAL {printf("parserINTLITERAL(val:%d, loc:%d, %d) ", yylval, @$.first_line, @$.first_column);}
	| COMMA {printf("parserCOMMA ");}
	| DOT {printf("parserDOT ");}
	| SEMICOLON {printf("parserSEMICOLON \n");}
	;

boolliteral: _TRUE {printf("parser_TRUE ");}
	| _FALSE {printf("parser_FALSE ");}
	;

sys: PUBLIC {printf("parserPUBLIC ");}
	| STATIC {printf("parserSTATIC ");}
	| CLASS {printf("parserCLASS ");}
	| IF {printf("parserIF ");}
	| ELSE {printf("parserELSE ");}
	| WHILE {printf("parserWHILE ");}
	| NEW {printf("parserNEW ");}
	| THIS {printf("parserTHIS ");}
	;

brace: LCURLYBRACE {printf("\nparserLCURLYBRACE \n");}
	| RCURLYBRACE {printf("\nparserRCURLYBRACE \n");}
	| LPAREN {printf("parserLPAREN ");}
	| RPAREN {printf("parserRPAREN ");}
	| LSQUAREBRACKET {printf("parserLSQUAREBRACKET ");}
	| RSQUAREBRACKET {printf("parserRSQUAREBRACKET ");}
	;

type: TYPE {printf("parserTYPE ");}
	| VOID {printf("parserVOID ");}
	;

booloperator: NOT {printf("parserNOT ");}
	| LESS {printf("parserLESS ");}
	| AND {printf("parserAND ");}
	;

arithoperator: EQUALS {printf("parserEQUALS ");}
	| PLUS {printf("parserPLUS ");}
	| MINUS {printf("parserMINUS ");}
	| MULTIPLY {printf("parserMULTIPLY ");}
	;

%%
