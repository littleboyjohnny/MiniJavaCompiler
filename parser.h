#define PARSER_PROCESS_RULE(left, right) parserProcessRule( #left, #right )


#ifdef PARSER_MAIN
int main( int argc, char** argv );
#endif

extern "C" int yylex();
extern "C" int yyparse();

void yyerror( const char * str );

void parserPrintDebugMessage( const char * left, const char * right );

void parserProcessRule( const char * left, const char * right );

