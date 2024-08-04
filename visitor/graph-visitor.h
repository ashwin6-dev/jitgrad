#pragma once

class Node;
class Const;
class Placeholder;
class Add;
class Sub;
class Mul;
class Div;

class GraphVisitor {
public:
    virtual void visit(Const* node) = 0;
    virtual void visit(Placeholder* node) = 0;
    virtual void visit(Add* node) = 0;
    virtual void visit(Sub* node) = 0;
    virtual void visit(Mul* node) = 0;
    virtual void visit(Div* node) = 0;
};