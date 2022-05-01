/* Verificando a sintaxe de um programa na linguagem ornitorrinco .orn */
%{
#include <stdio.h> 
%}
%token ID
%%
input:    /* empty */
        | input line
;
line:     '\n'
        | programa '\n'			{printf("Sintaxe ok para seu programa orn!\n");} ;
programa: '(' lista_comandos ')'	{;}
;
lista_comandos:	comando ';'		{;}
;
comando: ID '=' const			{;}
;
const:	'2'				{;}
;
%%
main ()
{
	yyparse ();
}
yyerror (s) /* Called by yyparse on error */
	char *s;
{
	printf ("Sintaxe nok para seu programa!\n", s);
}