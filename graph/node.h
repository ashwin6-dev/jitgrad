#pragma once

#include "../visitor/graph-visitor.h"

class Node {
public:
    virtual double get_value() = 0;
    virtual void accept(GraphVisitor* visitor) = 0;
};