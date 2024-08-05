#pragma once

#include "../visitor/graph-visitor.h"

class Node {
public:
    double get_value() { return 0; };
    virtual void accept(GraphVisitor* visitor) = 0;
};