parser: lex.yy.c parser.tab.c
	g++ -DPARSER_MAIN -DPARSER_DEBUG lex.yy.c parser.tab.c lexer.cpp parser.cpp -o parser.out

lexer: lex.yy.c parser.tab.c
	g++ -DLEXER_MAIN -DLEXER_DEBUG lex.yy.c parser.tab.c lexer.cpp -o lexer.out

parser.tab.c: parser.y
	bison -d parser.y

lex.yy.c: lexer.lex
	flex lexer.lex

clean:
	rm *.out *.yy.c *.tab.* *.output
