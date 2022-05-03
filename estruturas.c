#include "estruturas.h"
#include <stdio.h>
#include <string.h>

extern void incrementarEscopo(){
    escopo[++escopo_ponteiro] = ++escopo_atual;
}

extern void reduzirEscopo(){
    escopo[escopo_ponteiro] = -1;
    escopo_ponteiro--;
}

extern void inserirSimbolo(int l, int c , int e , bool f, char* t, char* n){
    simbolos_ponteiro++;
    tabela_simbolos[simbolos_ponteiro].linha = l;
    tabela_simbolos[simbolos_ponteiro].coluna = c;
    tabela_simbolos[simbolos_ponteiro].escopo = e;
    tabela_simbolos[simbolos_ponteiro].funcao = f;
    strcpy(tabela_simbolos[simbolos_ponteiro].tipo, t);
    strcpy(tabela_simbolos[simbolos_ponteiro].nome, n);


}
extern void imprimirTabelaSimbolos(){
    printf("Linha\t|Coluna\t|Escopo\t|Identif.|Tipo\t\t|Nome\n");
    int i;
    for (i = 0; i <= simbolos_ponteiro; i++){
        if(tabela_simbolos[i].funcao){
            if(strlen(tabela_simbolos[i].tipo) > 5){
                printf("%d\t|%d\t|%d\t|função  |%s\t|%s\n", 
                tabela_simbolos[i].linha,
                tabela_simbolos[i].coluna,
                tabela_simbolos[i].escopo,
                tabela_simbolos[i].tipo,
                tabela_simbolos[i].nome
                );
            } else {
                printf("%d\t|%d\t|%d\t|função  |%s\t\t|%s\n", 
                tabela_simbolos[i].linha,
                tabela_simbolos[i].coluna,
                tabela_simbolos[i].escopo,
                tabela_simbolos[i].tipo,
                tabela_simbolos[i].nome
                );
            }
        }
        else {
            if(strlen(tabela_simbolos[i].tipo) > 5){
                printf("%d\t|%d\t|%d\t|variável|%s\t|%s\n", 
                tabela_simbolos[i].linha,
                tabela_simbolos[i].coluna,
                tabela_simbolos[i].escopo,
                tabela_simbolos[i].tipo,
                tabela_simbolos[i].nome
                );
            } else {
                printf("%d\t|%d\t|%d\t|variável|%s\t\t|%s\n", 
                tabela_simbolos[i].linha,
                tabela_simbolos[i].coluna,
                tabela_simbolos[i].escopo,
                tabela_simbolos[i].tipo,
                tabela_simbolos[i].nome
                );
            }
            
        }
    }

}
extern void esvaziarTabela(){

}

extern void imprimirArvore(){

}

extern void esvaziarArvore(){

}
