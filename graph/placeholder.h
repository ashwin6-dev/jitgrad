#pragma once

#include "node.h"

class Placeholder : public Node {
    double value;

public:
    void set_value(double value);
    double get_value();
    void accept(GraphVisitor* visitor);
};