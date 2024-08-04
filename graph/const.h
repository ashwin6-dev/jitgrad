#pragma once

#include "node.h"

class Const : public Node {
    double value;

public:
    Const(double _value) : value(_value) {};
    double get_value();
    void accept(GraphVisitor* visitor);
};