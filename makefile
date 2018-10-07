example.out: lex.yy.c parser.tab.c
	gcc lex.yy.c parser.tab.c -o example.out

parser.tab.c: parser.y
	bison -d parser.y

lex.yy.c: lexer.lex
	flex lexer.lex
