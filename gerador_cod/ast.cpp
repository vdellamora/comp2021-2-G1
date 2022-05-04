#include <iostream>
#include <sstream>
#include "ast.h"
#include "gen.h"
using std::cout;
using std::endl;
using std::stringstream;

// ---------
// Statement
// ---------

Statement::Statement() : Node(NodeType::STMT) {

}

Statement::Statement(int type) : Node(type) {

}

void Statement::Gen() {

}

// ----------
// Expression
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

string Expression::ToString(){
    return token->lexeme;
}

string Expression::Type(){
    switch (type){
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
// Temp
// ----

int Temp::count = 0;

Temp::Temp(int etype) : 
    Expression(NodeType::TEMP, etype, nullptr), 
    number(++count)
{
}

string Temp::ToString(){
    stringstream ss;
    ss << "t" << number;
    return ss.str();
}

// --------
// Constant
// --------

Constant::Constant(int etype, Token *t) : Expression(NodeType::CONSTANT, etype, t) {

}

// ----------
// Identifier
// ----------

Identifier::Identifier(int etype, Token *t) : Expression(NodeType::IDENTIFIER, etype, t) {

}

// -------
// Logical
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
        //throw //SyntaxError;
    }
}

// ----------
// Relational
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
        //throw //SyntaxError;
    }
}

// ----------
// Arithmetic
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
        //throw //SyntaxError;
    }
}

// ------
// Assign
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
        //throw //SyntaxError;
    }
}

void Assign::Gen(){
    Expression * left = Lvalue(id);
    Expression * right = Rvalue(expr);
    cout << '\t' << left->ToString() << " = " << right->ToString() << endl;
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
