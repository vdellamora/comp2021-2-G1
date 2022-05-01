%{
#include <stdio.h>
#include <string.h>
#include "sintal.tab.h"

#define PREPARATOKEN; strcpy(yylval.token.nome, yytext); yylval.token.linha = linha; yylval.token.coluna = coluna;

int coluna = 1;
int linha = 1;
int qtd_erros = 0;
%}

letter [a-zA-Z]
id	{letter}+

digit      [0-9]
integer    {digit}+

tp_inteiro (int)
tp_vazio   (void)

op_add [+]
op_sub [-]
op_mul [*]
op_div [/]

op_igual  (==)
op_maig   (>=)
op_meig   (<=)
op_maior  [<]
op_menor  [>]
op_diff   (!=)
op_atr	  [=]

op_virgula [,]
op_pvirgula [;]

cmd_if		if
cmd_else	else
cmd_while	while
cmd_return	return

parent_esq [(]
parent_dir [)]
colch_esq  (\[)
colch_dir  (\])
chave_esq  (\{)
chave_dir  (\})

comment   \/\*[^\*\/]*\*\/

%%
{id}			     {printf("Identificador\n");           return id;}
{integer}		   {printf("Número inteiro\n");          return integer;}

{tp_inteiro}	 {printf("Tipo inteiro\n");            return tp_inteiro;}
{tp_vazio}		 {printf("Tipo vazio\n");              return tp_vazio;}

{op_add}		   {printf("Operador aditivo\n");        return op_add;}
{op_sub}		   {printf("Operador subtrativo\n");        return op_sub;}
{op_mul}		   {printf("Operador multiplicativo\n"); return op_mul;}
{op_div}		   {printf("Operador divisório\n"); return op_div;}

{op_igual}		   {printf("Operador igual\n");     return op_igual;}
{op_maior}		   {printf("Operador maior\n");     return op_maior;}
{op_menor}		   {printf("Operador menor\n");     return op_menor;}
{op_maig}		   {printf("Operador maior igual\n");     return op_maig;}
{op_meig}		   {printf("Operador menor igual\n");     return op_meig;}
{op_diff}		   {printf("Operador diferente\n");     return op_diff;}
{op_atr}		   {printf("Operador atribuição\n");     return op_atr;}

{op_virgula}	 {printf("Vírgula\n");                 return op_virgula;}
{op_pvirgula}	 {printf("Ponto e vírgula\n");         return op_pvirgula;}

{parent_esq}	   {printf("Parêntese esq\n");              return parent_esq;}
{parent_dir}	   {printf("Parêntese dir\n");              return parent_dir;}
{colch_esq}		   {printf("Colchete esq\n");               return colch_esq;}
{colch_dir}		   {printf("Colchete dir\n");               return colch_dir;}
{chave_esq}		   {printf("Chave esq\n");                  return chave_esq;}
{chave_dir}		   {printf("Chave dir\n");                  return chave_dir;}


{cmd_if}		  {printf("Comando if\n");               return cmd_if;}
{cmd_else}		{printf("Comando else\n");             return cmd_else;}
{cmd_while}		{printf("Comando while\n");            return cmd_while;}
{cmd_return}	{printf("Comando return\n");           return cmd_return;}



{comment}	    {printf("Comentário\n");               return comment;}
.             {printf("Cadeia indefinida \n");       qtd_erros++;}


%%
