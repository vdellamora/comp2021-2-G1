%{
#include <stdio.h>
%}

id	[a-zA-Z][a-zA-Z0-9]*\n

digit     [0-9]
integer   {digit}+
float     {digit}+[.]{digit}+

op_expr [+*/-]
op_atr	[=]

comment   (\*[^\*)]*\*)


%%
{id}		{printf("Identificador\n");}

{integer}	{printf("Número inteiro\n");}
{float}		{printf("Número real\n");}

{op_expr}	{printf("Operador expressão\n");}
{op_atr}	{printf("Operador atribuição\n");}


{comment}	{printf("Comentário\n");}
. {printf(":-(\n");}


%%


/* recomendavel declarar sempre funcao yywrap() */
int yywrap ();

/* programa principal */
main() {
  yylex(); /* scanner gerado por Flex */
}

int yywrap() {
 return 1;
}
