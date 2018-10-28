#include "../parser/parser.tab.h"

#include "../AST/interfaces/IAcceptable.h"
#include "../AST/interfaces/IAdditionalExpressionParam.h"
#include "../AST/interfaces/IAdditionalExpressionParamS.h"
#include "../AST/interfaces/IAdditionalParam.h"
#include "../AST/interfaces/IAdditionalParamS.h"
#include "../AST/interfaces/IClassDeclaration.h"
#include "../AST/interfaces/IClassDeclarationS.h"
#include "../AST/interfaces/IExpression.h"
#include "../AST/interfaces/IExpressionParamS.h"
#include "../AST/interfaces/IExtension.h"
#include "../AST/interfaces/IGoal.h"
#include "../AST/interfaces/IMainClass.h"
#include "../AST/interfaces/IMethodDeclaration.h"
#include "../AST/interfaces/IMethodDeclarationS.h"
#include "../AST/interfaces/IParams.h"
#include "../AST/interfaces/IStatement.h"
#include "../AST/interfaces/IStatementS.h"
#include "../AST/interfaces/IType.h"
#include "../AST/interfaces/IVarDeclaration.h"
#include "../AST/interfaces/IVarDeclarationS.h"

#define LEXER_PROCESS_TOKEN(token) lexerProcessToken(token, #token)

#define YY_USER_ACTION \
	TT_char_prev_pos = TT_char_pos; \
	if (yylloc.first_line < yylineno) \
		TT_char_pos = 1; \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = TT_char_pos; \
	TT_char_pos = TT_char_pos + yyleng;

extern long TT_char_pos;
extern long TT_char_prev_pos;


#ifdef LEXER_MAIN
int main( int argc, char** argv );
#endif

extern "C" int yylex();

void lexerPrintDebugMessage( const char * msg );

void lexerProcessToken( int token, const char * msg );
