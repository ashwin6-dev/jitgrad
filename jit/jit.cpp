#include "jit.h"
#include <iostream>

compiled JITVisitor::jit(Node* graph)
{
    reg_allocation = allocator.allocate_registers(graph);
    graph->accept(this);

    return emitter.compile();
}

void JITVisitor::visit(Placeholder* node)
{
    if (placeholder_disp.count(node) == 0) {
        placeholder_disp[node] = curr_placeholder_disp;
        curr_placeholder_disp += 8;
    }

    int displacement = placeholder_disp[node];

    emitter.movesd_memory_reg(reg_allocation[node], displacement);
}

void JITVisitor::visit(Const* node)
{

}

void JITVisitor::visit(Add* node)
{
    node->left->accept(this);
    node->right->accept(this);

    emitter.movesd_reg_reg(reg_allocation[node->left], reg_allocation[node]);
    emitter.addsd(reg_allocation[node->right], reg_allocation[node]);
}

void JITVisitor::visit(Sub* node)
{
    node->left->accept(this);
    node->right->accept(this);
    
    emitter.movesd_reg_reg(reg_allocation[node->left], reg_allocation[node]);
    emitter.subsd(reg_allocation[node->right], reg_allocation[node]);
}

void JITVisitor::visit(Mul* node)
{
    node->left->accept(this);
    node->right->accept(this);

    emitter.movesd_reg_reg(reg_allocation[node->left], reg_allocation[node]);
    emitter.mulsd(reg_allocation[node->right], reg_allocation[node]);
}

void JITVisitor::visit(Div* node)
{
    node->left->accept(this);
    node->right->accept(this);

    emitter.movesd_reg_reg(reg_allocation[node->left], reg_allocation[node]);
    emitter.divsd(reg_allocation[node->right], reg_allocation[node]);
}