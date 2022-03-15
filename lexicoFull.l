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
tipos      {tp_inteiro}|{tp_vazio}

op_adit [+-]
op_mult [*/]
op_comp (==)|<|>|(<=)|(>=)|(!=)
op_atr	[=]

op_virgula [,]
op_pvirgula [;]

cmd_if		if
cmd_else	else
cmd_while	while
cmd_return	return

parenteses [(]|[)]
colchetes (\[)|(\])
chaves (\{)|(\})

comment   \/\*[^\*\/]*\*\/

plvrReservada	{cmd_if}|{cmd_else}|{cmd_while}|{cmd_return}


%%
{id}			     {printf("Identificador\n");           return id;}

{integer}		   {printf("Número inteiro\n");          return integer;}
{tp_inteiro}	 {printf("Tipo inteiro\n");            return tp_inteiro;}
{tp_vazio}		 {printf("Tipo vazio\n");              return tp_vazio;}

{op_adit}		   {printf("Operador aditivo\n");        return op_adit;}
{op_mult}		   {printf("Operador multiplicativo\n"); return op_mult;}
{op_comp}		   {printf("Operador comparação\n");     return op_comp;}
{op_atr}		   {printf("Operador atribuição\n");     return op_atr;}

{op_virgula}	 {printf("Vírgula\n");                 return op_virgula;}
{op_pvirgula}	 {printf("Ponto e vírgula\n");         return op_pvirgula;}

{parenteses}	 {printf("Parênteses\n");              return parenteses;}
{colchetes}		 {printf("Colchetes\n");               return colchetes;}
{chaves}		   {printf("Chaves\n");                  return chaves;}


{cmd_if}		  {printf("Comando if\n");               return cmd_if;}
{cmd_else}		{printf("Comando else\n");             return cmd_else;}
{cmd_while}		{printf("Comando while\n");            return cmd_while;}
{cmd_return}	{printf("Comando return\n");           return cmd_return;}



{comment}	    {printf("Comentário\n");               return comment;}
.             {printf("Cadeia indefinida \n");       qtd_erros++;}


%%