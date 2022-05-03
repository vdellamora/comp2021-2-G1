/* Verificando a sintaxe de um programa na linguagem c-- .c-- */
%debug
%define parse.error verbose
%define lr.type canonical-lr
%{
#include <stdio.h>

extern int yylex();
extern FILE *yyin;
extern int yylex_destroy();
void yyerror(const char* e){
    printf("%s\n", e);
}

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

%type <node> numero

%%

numero: 
       integer {}
; 
        
%%
int main(){
    #ifdef YYDEBUF
        yydebug=1;
    #endif

	char nomeArqCIPL[64];
	char nomePastaArqCIPL[] = "./tests/";
	FILE *arquivoCIPL;

    printf("Insira o nome do arquivo dentro da pasta tests: ");
	scanf("%s", nomeArqCIPL);
	strcat(nomePastaArqCIPL, nomeArqCIPL);
	arquivoCIPL = fopen(nomePastaArqCIPL,"r");
	if(!arquivoCIPL){
		printf("Nao foi possível abrir arquivo.\n");
		return -1;
	}
	yyin = arquivoCIPL;

    escopo_atual = 0;
    escopo_ponteiro = 0;
    simbolos_ponteiro = -1;

	yyparse();

    imprimirTabelaSimbolos();


	fclose(arquivoCIPL);
    esvaziarTabela();
    esvaziarArvore();
	yylex_destroy();
	return 0;
}