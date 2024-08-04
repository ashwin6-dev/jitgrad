#include "placeholder.h"

void Placeholder::set_value(double value)
{
    this->value = value;
}

double Placeholder::get_value()
{
    return value;
}

void Placeholder::accept(GraphVisitor* visitor)
{
    visitor->visit(this);
}