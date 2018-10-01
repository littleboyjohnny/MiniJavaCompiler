lexer.out: lex.yy.c
	gcc -c lex.yy.c -o lexer.out

lex.yy.c: lexer.lex
	flex lexer.lex
