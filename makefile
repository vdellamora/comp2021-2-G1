compile:
	bison -d sintatico.y -Wcounterexamples
	flex lexicoFull.l
	g++ -g sintatico.tab.c lex.yy.c -otradutor -Wall