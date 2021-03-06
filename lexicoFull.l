%{
#include <stdio.h>
#include <string.h>
#include "sintatico.tab.h"

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
cmd_leia  scan
cmd_escreva  print

parent_esq [(]
parent_dir [)]
colch_esq  (\[)
colch_dir  (\])
chave_esq  (\{)
chave_dir  (\})

comment   \/\*[^\*\/]*\*\/

%%
\n 					{linha++; coluna = 1;}
[ \t]+				{coluna += yyleng;}

{integer}		   	{PREPARATOKEN; coluna += yyleng;	return integer;}

{tp_inteiro}	 	{PREPARATOKEN; coluna += yyleng;	return tp_inteiro;}
{tp_vazio}		 	{PREPARATOKEN; coluna += yyleng;	return tp_vazio;}

{op_add}		   	{PREPARATOKEN; coluna += yyleng;	return op_add;}
{op_sub}		   	{PREPARATOKEN; coluna += yyleng;	return op_sub;}
{op_mul}		   	{PREPARATOKEN; coluna += yyleng;	return op_mul;}
{op_div}		   	{PREPARATOKEN; coluna += yyleng;	return op_div;}

{op_igual}		   	{PREPARATOKEN; coluna += yyleng;	return op_igual;}
{op_maior}		   	{PREPARATOKEN; coluna += yyleng;	return op_maior;}
{op_menor}		   	{PREPARATOKEN; coluna += yyleng;	return op_menor;}
{op_maig}		   	{PREPARATOKEN; coluna += yyleng;	return op_maig;}
{op_meig}		   	{PREPARATOKEN; coluna += yyleng;	return op_meig;}
{op_diff}		   	{PREPARATOKEN; coluna += yyleng;	return op_diff;}
{op_atr}		   	{PREPARATOKEN; coluna += yyleng;	return op_atr;}

{op_virgula}	 	{PREPARATOKEN; coluna += yyleng;	return op_virgula;}
{op_pvirgula}	 	{PREPARATOKEN; coluna += yyleng;	return op_pvirgula;}

{parent_esq}	  	{PREPARATOKEN; coluna += yyleng;	return parent_esq;}
{parent_dir}	 	{PREPARATOKEN; coluna += yyleng;	return parent_dir;}
{colch_esq}		  	{PREPARATOKEN; coluna += yyleng;	return colch_esq;}
{colch_dir}		  	{PREPARATOKEN; coluna += yyleng;	return colch_dir;}
{chave_esq}		  	{PREPARATOKEN; coluna += yyleng;	return chave_esq;}
{chave_dir}		  	{PREPARATOKEN; coluna += yyleng;	return chave_dir;}


{cmd_if}		  	{PREPARATOKEN; coluna += yyleng;	return cmd_if;}
{cmd_else}			{PREPARATOKEN; coluna += yyleng;	return cmd_else;}
{cmd_while}			{PREPARATOKEN; coluna += yyleng;	return cmd_while;}
{cmd_return}		{PREPARATOKEN; coluna += yyleng;	return cmd_return;}
{cmd_leia}      {PREPARATOKEN; coluna += yyleng;  return cmd_leia;}
{cmd_escreva}   {PREPARATOKEN; coluna += yyleng;  return cmd_escreva;}

{id}			    {PREPARATOKEN; coluna += yyleng;	return id;}



{comment}	    	{printf("Comentário\n");			return comment;}
.             		{printf("Cadeia indefinida: %s\nLinha: %d\nColuna: %d\n", yytext, linha, coluna); coluna += yyleng; qtd_erros++;}


%%

int yywrap() {
  return 1;
}
