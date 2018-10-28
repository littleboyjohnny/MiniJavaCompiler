parser: lex.yy.c parser.tab.c
	g++ -ggdb -std=c++17 -DPARSER_MAIN -DPARSER_DEBUG lexer/lex.yy.c parser/parser.tab.c lexer/lexer.cpp parser/parser.cpp -o build/parser.out

lexer: lex.yy.c parser.tab.c
	g++ -ggdb -std=c++17 -DLEXER_MAIN -DLEXER_DEBUG lexer/lex.yy.c parser/parser.tab.c lexer/lexer.cpp parser/parser.cpp -o build/lexer.out

parser.tab.c: parser/parser.y
	bison -d parser/parser.y
	mv parser.output parser/
	mv parser.tab.c parser/
	mv parser.tab.h parser/

lex.yy.c: lexer/lexer.lex
	flex lexer/lexer.lex
	mv lex.yy.c lexer/

clean:
	rm -rf build/* lexer/*.yy.c parser/*.tab.* parser/*.output
