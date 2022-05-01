/* Verificando a sintaxe de um programa na linguagem c-- .c-- */
%debug
%define parse.error verbose
%define lr.type canonical-lr
%{
#include <stdio.h> 
%}
%token <token> letter
%token <token> id
%token <token> digit
%token <token> integer
%token <token> tp_inteiro
%token <token> tp_vazio
%token <token> op_add 
%token <token> op_sub 
%token <token> op_mul 
%token <token> op_div 
%token <token> op_igual
%token <token> op_maig
%token <token> op_meig
%token <token> op_maior
%token <token> op_menor
%token <token> op_diff
%token <token> op_atr
%token <token> op_virgula
%token <token> op_pvirgula
%token <token> cmd_if
%token <token> cmd_else
%token <token> cmd_while
%token <token> cmd_return
%token <token> parent_esq
%token <token> parent_dir
%token <token> colch_esq
%token <token> colch_dir
%token <token> chave_esq
%token <token> chave_dir
%token <token> comment

%type <galho> programa
%type <galho> declaracoesIniciais
%type <galho> declaracoes
%type <galho> funcoes
%type <galho> funcao
%type <galho> paramList
%type <galho> parametros

%type <galho> comandos
%type <galho> comando
%type <galho> declaracao
%type <galho> atribuicao
%type <galho> retorno
%type <galho> impressao
%type <galho> leitura

%type <galho> condicao
%type <galho> condSe
%type <galho> condSeSenao
%type <galho> repeticao
%type <galho> exprLogica
%type <galho> comparacao

%type <galho> chamadaFuncao
%type <galho> paramChamada
%type <galho> params

%type <galho> termo
%type <galho> numero
%type <galho> expressao
%type <galho> exprLista
%%
programa :
    declaracoesIniciais {}
    | comandos {}
;

declaracoesIniciais :
    declaracoes funcoes     {}
;

declaracoes :
    declaracao op_endLine declaracoes           {}
    | declaracao op_endLine                     {}
    | {}
;
funcoes :
    funcao funcoes                  {}
    | funcao                        {}
    | {}
;

funcao :
    tipo variable '(' paramList ')' '{' comandos '}' {
        inserirSimbolo(
            $2.linha,
            $2.coluna,
            escopo[escopo_ponteiro],
            1,
            $1.nome,
            $2.nome
        );
    }
;
paramList :
    parametros                              {}
    | declaracao                            {}
    | {}
;
parametros :
    declaracao op_virgula parametros        {}
    | declaracao                            {}
;


comandos :
    comando comandos                {}
    | comando                       {}
    | {}
;

comando :
    declaracoes                     {}
    | atribuicao op_endLine         {}
    | retorno op_endLine            {}
    | impressao op_endLine          {}
    | leitura op_endLine            {}
    | condicao                      {}
    | repeticao                     {}
    | chamadaFuncao op_endLine      {}
;

declaracao :
    tipo variable {
        inserirSimbolo(
            $2.linha,
            $2.coluna,
            escopo[escopo_ponteiro],
            0,
            $1.nome,
            $2.nome
        );
    }
;
atribuicao :
    variable op_atr termo           {}
;
retorno :
    cmd_return termo                {}
;
impressao :
    output '(' termo ')'            {}
    | output '(' cadeia ')'         {}
;
leitura :
    input '(' variable ')'          {}
;


condicao :
    condSe                                          {}
    | condSeSenao                                   {}
;
condSe :
    cmd_if '(' exprLogica ')' '{' comandos '}'      {}
;
condSeSenao :
    condSe cmd_else '{' comandos '}'                {}
    | condSe cmd_else comando               {}
;
repeticao :
    cmd_for '(' atribuicao op_endLine exprLogica op_endLine atribuicao ')' '{' comandos '}'     {}
;
exprLogica :
    comparacao op_logic exprLogica          {}
    | comparacao                            {}
;
comparacao :
    termo op_comp termo                     {}
;



chamadaFuncao :
    variable '(' paramChamada ')'           {
    }
;
paramChamada :
    params                                  {}
    | termo                                 {}
    | {}
;
params :
    termo op_virgula params                 {}
    | termo                                 {}
;


termo :
    variable                                {}
    | numero                                {}
    | expressao                             {}
    | chamadaFuncao                         {}
;
numero :
    integer                                 {}
    | floaty                                 {}
;
expressao :
    termo op_expr termo                     {}
    | exprLista                             {}
;
exprLista :
    termo op_lista variable                    {}
    | op_lista variable                        {}
;





input:    /* empty */
        | input line
;
line:     '\n'
        | programa '\n'			{printf("Sintaxe ok para seu programa c--!\n");} ;
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