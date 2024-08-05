#include "reg-allocator.h"
#include <iostream>

reg_allocation RegAllocator::allocate_registers(Node* graph)
{
    queue = std::vector<Node*> { graph };
    int prev_len = 0;
    int index = 0;

    while (prev_len != queue.size()) {
        prev_len = queue.size();
        queue[index]->accept(this);
        index++;
    }

    int curr_reg = 0;

    for (int i = 0; i < queue.size() - 2; i++) {
        Node* node = queue[i];
        Node* left = queue[i + 1];
        Node* right = queue[i + 2];

        if (allocation.count(node) == 0)
            allocation[node] = curr_reg++;

        if (allocation.count(left) == 0)
            allocation[left] = allocation[node];

        if (allocation.count(right) == 0)
            allocation[right] = allocation[left] + 1;
    }

    return allocation;
}

void RegAllocator::visit(Add* node)
{
    Node* left = node->left;
    Node* right = node->right;

    queue.push_back(left);
    queue.push_back(right);
}

void RegAllocator::visit(Sub* node)
{
    Node* left = node->left;
    Node* right = node->right;

    queue.push_back(left);
    queue.push_back(right);
}

void RegAllocator::visit(Mul* node)
{
    Node* left = node->left;
    Node* right = node->right;

    queue.push_back(left);
    queue.push_back(right);
}

void RegAllocator::visit(Div* node)
{
    Node* left = node->left;
    Node* right = node->right;

    queue.push_back(left);
    queue.push_back(right);
}