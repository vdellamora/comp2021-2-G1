//Árvore Sintática, Tabela de Símbolos e a Pilha(vetor) de escopo
#include <stdbool.h>
//Escopo
int escopo_atual;
int escopo_ponteiro;
int escopo[1000];

extern void incrementarEscopo();
extern void reduzirEscopo();




//Tabela de Símbolos
typedef struct simbolo{
    int linha, coluna, escopo;
    bool funcao;
    char tipo[30], nome[30];
} Simbolo;
int simbolos_ponteiro;
Simbolo tabela_simbolos[5000];

extern void inserirSimbolo(int, int, int, bool, char*, char*);
extern void imprimirTabelaSimbolos();
extern void esvaziarTabela();




//Árvore Sintática, 4 galhos por causa do for
typedef struct galho{
    struct galho* g1;
    struct galho* g2;
    struct galho* g3;
    struct galho* g4;

    char nome[100];
} Galho;

extern void imprimirArvore();
extern void esvaziarArvore();