#include <iostream>
//#include "error.h"
#include <sstream>
#include "gen.h"
using std::cout;
using std::endl;
using std::stringstream;

Expression *Lvalue(Expression *n){
    if (n->node_type == NodeType::IDENTIFIER){
        return n;
    }
    else{
        stringstream ss;
        ss << "Expressão \'" << n->ToString() << "\' não possui valor-l";
        throw //SyntaxError;
    }
}

Expression *Rvalue(Expression *n){
    if (n->node_type == NodeType::IDENTIFIER || n->node_type == NodeType::CONSTANT){
        return n;
    }
    else if (n->node_type == NodeType::ARI){   
        Arithmetic * ari = (Arithmetic*) n;
        Temp * t = new Temp(ari->type);
        Expression * e1 = Rvalue(ari->expr1);
        Expression * e2 = Rvalue(ari->expr2);
        cout << '\t' << t->ToString() << " = " << e1->ToString() << " " << ari->ToString() << " " << e2->ToString() << endl;
        return t;
    }
    else if (n->node_type == NodeType::REL){
        Relational * rel = (Relational*) n;
        Temp * t = new Temp(rel->type);
        Expression * e1 = Rvalue(rel->expr1);
        Expression * e2 = Rvalue(rel->expr2);
        cout << '\t' << t->ToString() << " = " << e1->ToString() << " " << rel->ToString() << " " << e2->ToString() << endl;
        return t;
    }
    else if (n->node_type == NodeType::LOG){
        Logical * log = (Logical*) n;
        Temp * t = new Temp(log->type);
        Expression * e1 = Rvalue(log->expr1);
        Expression * e2 = Rvalue(log->expr2);
        cout << '\t' << t->ToString() << " = " << e1->ToString() << " " << log->ToString() << " " << e2->ToString() << endl;
        return t;
    }
    else if (n->node_type == NodeType::ASSIGN){
        cout << "falta implementar" << endl;
    }
    else{
        stringstream ss;
        ss << "Expressão \'" << n->ToString() << "\' não possui valor-r";
        throw //SyntaxError;
    }
}