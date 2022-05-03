#include <iostream>
#include "error.h"
#include "gen.h"
using std::cout;
using std::endl;

extern Lexer * scanner;

// construção do lado esquerda arvore
// no caso vai representar apenas uma variável de atribuição
Expression *Lvalue(Expression *n){
    if (n->node_type == NodeType::IDENTIFIER){
        return n;
    }
}

// lado direito da arvore...que representa um expressão a ser calculada
Expression *Rvalue(Expression *n){
    if (n->node_type == NodeType::IDENTIFIER || n->node_type == NodeType::CONSTANT){
        return n;
    }
    else if (n->node_type == NodeType::ARI){   
        Arithmetic * ari = (Arithmetic*) n;
        Temp * t = new Temp(ari->type);
        Expression * e1 = Rvalue(ari->expr1);
        Expression * e2 = Rvalue(ari->expr2);
        // mostrar na tela respectiva tradução
        return t;
    }
    else if (n->node_type == NodeType::REL){
        Relational * rel = (Relational*) n;
        Temp * t = new Temp(rel->type);
        Expression * e1 = Rvalue(rel->expr1);
        Expression * e2 = Rvalue(rel->expr2);
        // mostrar na tela respectiva tradução
        return t;
    }
    else if (n->node_type == NodeType::LOG){
        Logical * log = (Logical*) n;
        Temp * t = new Temp(log->type);
        Expression * e1 = Rvalue(log->expr1);
        Expression * e2 = Rvalue(log->expr2);
        // mostrar na tela respectiva tradução
        return t;
    }
    else if (n->node_type == NodeType::ASSIGN){
        //Expression * left = Lvalue(acc->id);
        Expression * right = Rvalue(acc->expr);
        // mostrar na tela respectiva tradução
        return right;
    }
}