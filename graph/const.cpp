#include "const.h"

double Const::get_value()
{
    return value;
}

void Const::accept(GraphVisitor* visitor)
{
    visitor->visit(this);
}