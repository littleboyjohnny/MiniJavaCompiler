parser: lex.yy.c parser.tab.c
	g++ -ggdb -DPARSER_MAIN -DPARSER_DEBUG lex.yy.c parser.tab.c lexer.cpp parser.cpp -o build/parser.out

lexer: lex.yy.c parser.tab.c
	g++ -ggdb -DLEXER_MAIN -DLEXER_DEBUG lex.yy.c parser.tab.c lexer.cpp parser.cpp -o build/lexer.out

parser.tab.c: parser.y
	bison -d parser.y

lex.yy.c: lexer.lex
	flex lexer.lex

clean:
	rm -rf build/* *.yy.c *.tab.* *.output
