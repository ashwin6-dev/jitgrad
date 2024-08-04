#pragma once

#include "../emitter/emitter.h"
#include "../visitor/graph-visitor.h"
#include <unordered_map>

#include "../graph/const.h"
#include "../graph/placeholder.h"
#include "../graph/ops.h"

class JITVisitor : public GraphVisitor {
private:
    Emitter emitter;

    std::unordered_map<double, int> value_disp;
    std::unordered_map<Placeholder*, int> placeholder_disp;

    std::unordered_map<Node*, int> reg_allocation;

public:
    JITVisitor();
    
    compiled jit(Node* graph);
    void visit(Const* node);
    void visit(Placeholder* node);
    void visit(Add* node);
    void visit(Sub* node);
    void visit(Mul* node);
    void visit(Div* node);
};