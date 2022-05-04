#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

typedef struct Token {
        int line;
        int column;
        int scope;
        char* content;
} Token; 

typedef struct Node {
    char*  identifier;
    struct Node*  leftChild;
    struct Node*  rightChild;
    Token* token;
    char*  returnType;
} Node;

extern Node* makeNode (char* identifier);
extern int isSameType (char* lhs, char* rhs);
extern int isError (char* type);
extern int isInt (char* type);
extern void printTree(Node* tree_node, int nivel);

#endif