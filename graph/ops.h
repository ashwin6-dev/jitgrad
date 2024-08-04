#pragma once

#include "node.h"
#include <memory>

class BinOp : public Node {
protected:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

public:
    BinOp(std::shared_ptr<Node> l, std::shared_ptr<Node> r) : left(l), right(r) {};
};

class Add : public BinOp {
public:
    Add(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};

class Sub : public BinOp {
public:
    Sub(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};

class Mul : public BinOp {
public:
    Mul(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};

class Div : public BinOp {
public:
    Div(std::shared_ptr<Node> left, std::shared_ptr<Node> right) : BinOp(left, right) {};
    void accept(GraphVisitor* visitor);
};