a.out: lex.yy.c
	gcc lex.yy.c -ll

lex.yy.c: lexer.l
	flex lexer.l

clean:
	rm -f lex.yy.c a.out

.PHONY: clean

