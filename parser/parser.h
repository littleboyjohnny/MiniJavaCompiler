#define PARSER_PROCESS_RULE(left, right) parserProcessRule( #left, #right )

#include "../AST/include/AdditionalExpressionParam.hpp"
#include "../AST/include/AdditionalExpressionParamS.hpp"
#include "../AST/include/AdditionalParam.hpp"
#include "../AST/include/AdditionalParamS.hpp"
#include "../AST/include/ArrayAssignmentStatement.hpp"
#include "../AST/include/BooleanType.hpp"
#include "../AST/include/CurlyBraceStatement.hpp"
#include "../AST/include/CustomType.hpp"
#include "../AST/include/DotExpression.hpp"
#include "../AST/include/ExpressionParamS.hpp"
#include "../AST/include/FalseExpression.hpp"
#include "../AST/include/Goal.hpp"
#include "../AST/include/IdentifierExpression.hpp"
#include "../AST/include/IfElseStatement.hpp"
#include "../AST/include/IntArrayType.hpp"
#include "../AST/include/IntliteralExpression.hpp"
#include "../AST/include/IntType.hpp"
#include "../AST/include/LengthExpression.hpp"
#include "../AST/include/NewArrayExpression.hpp"
#include "../AST/include/NewIdentifierExpression.hpp"
#include "../AST/include/NotExpression.hpp"
#include "../AST/include/Params.hpp"
#include "../AST/include/ParensExpression.hpp"
#include "../AST/include/PrintlnStatement.hpp"
#include "../AST/include/SquarebracketsExpression.hpp"
#include "../AST/include/StatementS.hpp"
#include "../AST/include/TerminalIdentifier.hpp"
#include "../AST/include/TerminalIntliteral.hpp"
#include "../AST/include/ThisExpression.hpp"
#include "../AST/include/TrueExpression.hpp"
#include "../AST/include/VarAssignmentStatement.hpp"
#include "../AST/include/WhileStatement.hpp"
#include "../AST/include/ClassDeclaration.hpp"
#include "../AST/include/MainClass.hpp"
#include "../AST/include/ClassDeclarationS.hpp"
#include "../AST/include/Extension.hpp"
#include "../AST/include/VarDeclarationS.hpp"
#include "../AST/include/VarDeclaration.hpp"
#include "../AST/include/MethodDeclarationS.hpp"
#include "../AST/include/MethodDeclaration.hpp"
#include "../AST/include/BinaryOpExpression.hpp"


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


#ifdef PARSER_MAIN
int main( int argc, char** argv );
#endif

extern "C" int yylex();
extern "C" int yyparse();

void yyerror (void*& node, char const *msg);

void parserPrintDebugMessage( const char * left, const char * right );

void parserProcessRule( const char * left, const char * right );

