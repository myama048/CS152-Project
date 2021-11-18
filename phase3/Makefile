all: phase3
phase3.tab.c phase3.tab.h:	phase3.y
	bison -t -v -d phase3.y
lex.yy.c: phase3.lex phase3.tab.h
	flex phase3.lex 
phase3: lex.yy.c phase3.tab.c phase3.tab.h
	g++ -std=c++11 -g -Wall -ansi -pedantic -o phase3 phase3.tab.c lex.yy.c
clean:
	rm phase3 phase3.tab.c lex.yy.c phase3.tab.h phase3.output
