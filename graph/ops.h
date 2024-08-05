#pragma once

#include "node.h"
class BinOp : public Node {
public:
    Node* left;
    Node* right;

    BinOp(Node* l, Node* r) : left(l), right(r) {};
};

class Add : public BinOp {
public:
    Add(Node* left, Node* right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};

class Sub : public BinOp {
public:
    Sub(Node* left, Node* right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};

class Mul : public BinOp {
public:
    Mul(Node* left, Node* right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};

class Div : public BinOp {
public:
    Div(Node* left, Node* right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};