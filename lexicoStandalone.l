%{
#include <stdio.h>

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
{id}			{printf("Identificador\n");}

{integer}		{printf("Número inteiro\n");}
{tp_inteiro}	{printf("Tipo inteiro\n");}
{tp_vazio}		{printf("Tipo vazio\n");}

{op_adit}		{printf("Operador aditivo\n");}
{op_mult}		{printf("Operador multiplicativo\n");}
{op_comp}		{printf("Operador comparação\n");}
{op_atr}		{printf("Operador atribuição\n");}

{op_virgula}	{printf("Vírgula\n");}
{op_pvirgula}	{printf("Ponto e vírgula\n");}

{parenteses}	{printf("Parênteses\n");}
{colchetes}		{printf("Colchetes\n");}
{chaves}		{printf("Chaves\n");}


{cmd_if}		{printf("Comando if\n");}
{cmd_else}		{printf("Comando else\n");}
{cmd_while}		{printf("Comando while\n");}
{cmd_return}	{printf("Comando return\n");}



{comment}	{printf("Comentário\n");}
. {printf("Cadeia indefinida \n");}


%%

int yywrap ();

int main() {
  yylex(); /* scanner gerado por Flex */

  return 0;
}

int yywrap() {
 return 1;
}
