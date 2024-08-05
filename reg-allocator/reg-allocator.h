#pragma once

#include "../visitor/graph-visitor.h"
#include <unordered_map>
#include <vector>

#include "../graph/const.h"
#include "../graph/placeholder.h"
#include "../graph/ops.h"


#include <iostream>

typedef std::unordered_map<Node*, int> reg_allocation;

class RegAllocator : public GraphVisitor {
    reg_allocation allocation;
    std::vector<Node*> queue;

public:
    reg_allocation allocate_registers(Node* graph);
    void visit(Const* node) {};
    void visit(Placeholder* node) {};
    void visit(Add* node);
    void visit(Sub* node);
    void visit(Mul* node);
    void visit(Div* node);
};