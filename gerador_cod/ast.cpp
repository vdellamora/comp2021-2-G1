#include <iostream>
#include <sstream>
#include "ast.h"
#include "error.h"
#include "gen.h"
using std::cout;
using std::endl;
using std::stringstream;

extern Lexer *scanner;
// ----
// Node
// ----

unsigned Node::labels = 0;

Node::Node() : 
    node_type(NodeType::UNKNOWN) 
{

}

Node::Node(int t) : 
    node_type(t) 
{

}

string Node::ToString() { 
    return ""; 
}

unsigned Node::NewLabel() { 
    return ++labels; 
}

// ---------
// Statement
// ---------

Statement::Statement() : 
    Node(NodeType::STMT) 
{

}

Statement::Statement(int type) : 
    Node(type) 
{

}

void Statement::Gen() {

}

// ----------
// Expressões
// ----------

Expression::Expression(Token *t) : 
    Node(NodeType::EXPR),
    type(ExprType::VOID),
    token(t)
{

}

Expression::Expression(int ntype, int etype, Token *t) : 
    Node(ntype), 
    type(etype), 
    token(t) 
{

}

string Expression::ToString()
{
    return token->lexeme;
}

string Expression::Type()
{
    switch (type)
    {
    case ExprType::INT:
        return "int";
        break;
    case ExprType::BOOL:
        return "bool";
        break;
    default:
        return "void";
    }
}

// ----
// Criação de variáveis Temporárias
// ----

int Temp::count = 0;

Temp::Temp(int etype) : 
    Expression(NodeType::TEMP, etype, nullptr), 
    number(++count)
{
}

string Temp::ToString()
{
    stringstream ss;
    ss << "t" << number;
    return ss.str();
}

// --------
// Constantes
// --------

Constant::Constant(int etype, Token *t) : 
    Expression(NodeType::CONSTANT, etype, t) 
{

}

// ----------
// Identifier
// ----------

Identifier::Identifier(int etype, Token *t) : 
    Expression(NodeType::IDENTIFIER, etype, t) 
{

}

// -------
// Expressões Lógicas
// -------

Logical::Logical(Token *t, Expression *e1, Expression *e2) : 
    Expression(NodeType::LOG, ExprType::BOOL, t), 
    expr1(e1), 
    expr2(e2)
{
    // verificação de tipos
    if (expr1->type != ExprType::BOOL || expr2->type != ExprType::BOOL){
        stringstream ss;
        ss << "\'" << token->lexeme << "\' usado com operandos não booleanos ("
           << expr1->ToString() << ":" << expr1->Type() << ") ("
           << expr2->ToString() << ":" << expr2->Type() << ") ";
        throw SyntaxError{scanner->Lineno(), ss.str()};
    }
}

// ----------
// Expressões Relationais
// ----------

Relational::Relational(Token *t, Expression *e1, Expression *e2) : 
    Expression(NodeType::REL, ExprType::BOOL, t), 
    expr1(e1), 
    expr2(e2)
{
    // verificação de tipos
    if (expr1->type != expr2->type){
        stringstream ss;
        ss << "\'" << token->lexeme << "\' usado com operandos de tipos diferentes ("
           << expr1->ToString() << ":" << expr1->Type() << ") ("
           << expr2->ToString() << ":" << expr2->Type() << ") ";
        throw SyntaxError{scanner->Lineno(), ss.str()};
    }
}

// ----------
// Expressão aritméticas
// ----------

Arithmetic::Arithmetic(int etype, Token *t, Expression *e1, Expression *e2) : 
    Expression(NodeType::ARI, etype, t), 
    expr1(e1), 
    expr2(e2)
{
    // verificação de tipos
    if (expr1->type != expr2->type){
        stringstream ss;
        ss << "\'" << token->lexeme << "\' usado com operandos de tipos diferentes ("
           << expr1->ToString() << ":" << expr1->Type() << ") ("
           << expr2->ToString() << ":" << expr2->Type() << ") ";
        throw SyntaxError{scanner->Lineno(), ss.str()};
    }
}

// ------
// Atribuições
// ------

Assign::Assign(Expression *i, Expression *e) : 
    Statement(NodeType::ASSIGN), 
    id(i), 
    expr(e)
{
    // verificação de tipos
    if (id->type != expr->type){
        stringstream ss;
        ss << "\'=\' usado com operandos de tipos diferentes ("
           << id->ToString() << ":" << id->Type() << ") ("
           << expr->ToString() << ":" << expr->Type() << ") ";
        throw SyntaxError{scanner->Lineno(), ss.str()};
    }
}

void Assign::Gen(){
    Expression * left = Lvalue(id);
    Expression * right = Rvalue(expr);
    cout << '\t' << left->ToString() << " = " << right->ToString() << endl;
}

// ----
// If
// ----

If::If(Expression *e, Statement *s) : 
    Statement(NodeType::IF_STMT), 
    expr(e), 
    stmt(s)
{
    // verificação de tipos
    if (expr->type != ExprType::BOOL)
    {
        stringstream ss;
        ss << "expressão condicional \'" << expr->ToString() << "\' não booleana";
        throw SyntaxError{scanner->Lineno(), ss.str()};
    }

    // cria novo rótulo
    after = NewLabel();
}

void If::Gen(){
    Expression * n = Rvalue(expr);
    cout << "\tifFalse " << n->ToString() << " goto L" << after << endl;
    stmt->Gen();
    cout << 'L' << after << ':' << endl;
}

// -----
// While
// -----

While::While(Expression *e, Statement *s) : 
    Statement(NodeType::WHILE_STMT), 
    expr(e), 
    stmt(s) 
{
    
}

void While::Gen(){
    
}