#include "ops.h"
#include <iostream>

void Add::accept(GraphVisitor* visitor)
{
    visitor->visit(this);
}

void Sub::accept(GraphVisitor* visitor)
{
    visitor->visit(this);
}

void Mul::accept(GraphVisitor* visitor)
{
    visitor->visit(this);
}

void Div::accept(GraphVisitor* visitor)
{
    visitor->visit(this);
}