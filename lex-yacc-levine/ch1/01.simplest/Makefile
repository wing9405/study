a.out: lex.yy.c
	gcc lex.yy.c -ll

lex.yy.c: simplest.l
	flex simplest.l

clean:
	rm -f lex.yy.c a.out

.PHONY: clean

