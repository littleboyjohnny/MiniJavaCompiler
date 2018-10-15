parser: lex.yy.c parser.tab.c
	gcc -DPARSER_MAIN -DLEXER_DEBUG lex.yy.c parser.tab.c -o parser.out

lexer: lex.yy.c parser.tab.c
	gcc -DLEXER_MAIN -DLEXER_DEBUG lex.yy.c parser.tab.c -o lexer.out

parser.tab.c: parser.y
	bison -d parser.y

lex.yy.c: lexer.lex
	flex lexer.lex

clean:
	rm *.out *.yy.c *.tab.* *.output
