#ifndef COMPILER_AST
#define COMPILER_AST

//#include "lexer.h"

enum NodeType{
    STMT,
    EXPR,
    CONSTANT,
    IDENTIFIER,
    LOG,
    REL,
    ARI,
    ASSIGN,
    WHILE_STMT,
    TEMP
};

enum ExprType{
    VOID,
    INT,
    BOOL
};

struct Node{
    int node_type;
    static unsigned labels;

    Node();
    Node(int t);
    virtual string ToString();
    unsigned NewLabel();
};

struct Statement : public Node{
    Statement();
    Statement(int type);
    virtual void Gen();
};

struct Expression : public Node{
    int type;
    Token * token;
        
    Expression(Token *t);
    Expression(int ntype, int etype, Token *t);
    virtual string ToString();
    string Type();
};

struct Temp : public Expression{
    static int count;
    int number;
    Temp(int etype);
    string ToString();
};

struct Constant : public Expression{
    Constant(int etype, Token *t);
};

struct Identifier : public Expression{
    Identifier(int etype, Token *t);
};

struct Logical : public Expression{
    Expression *expr1;
    Expression *expr2;
    Logical(Token *t, Expression *e1, Expression *e2);
};

struct Relational : public Expression{
    Expression *expr1;
    Expression *expr2;
    Relational(Token *t, Expression *e1, Expression *e2);
};

struct Arithmetic : public Expression{
    Expression *expr1;
    Expression *expr2;
    Arithmetic(int etype, Token *t, Expression *e1, Expression *e2);
};

struct Assign : public Statement{
    Expression *id;
    Expression *expr;
    Assign(Expression *i, Expression *e);
    void Gen();
};

struct While : public Statement{
    Expression *expr;
    Statement *stmt;
    While(Expression *e, Statement *s);
    void Gen();
};

#endif