#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AbstractSyntaxTree.hpp"
#define BLUE "\033[1;34:40m"
#define RED "\033[1;31:40m"
#define GREEN "\033[1;32:40m"
#define MAGENTA "\033[1;35:40m"
#define CYAN "\033[1;36:40m"
#define YELLOW "\033[1;33:40m"
#define REGULAR "\033[0m"

extern Node* makeNode (char* identifier) {    
    Node* node = (Node*) malloc(sizeof(Node));
    node->identifier = strdup(identifier);
    return node;
}

extern int isSameType (char* lhs, char* rhs) {
    return !strcmp(lhs, rhs);
}

extern int isInt (char* type) {
    return isSameType(type, "int");
}

extern int isError(char* type) {
    return isSameType(type, "undefined") || isSameType(type, "error");
}

extern void printTree(Node* node, int level) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("-");
    }

    if(node->token != NULL) {
        printf(":"GREEN" %s  "REGULAR, node->token->content);
    }
    
    if (!isError(node->returnType)) {
        printf(""RED"[ TYPE: %s ]  "REGULAR"", node->returnType);
    }

    printTree(node->leftChild, level + 1);
    printTree(node->rightChild, level + 1);

}
