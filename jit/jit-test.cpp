#include "jit.h"
#include <iostream>

int main()
{
    Placeholder p1;
    Placeholder p2;
    Add r(&p1, &p2);

    Placeholder p3;
    Div m(&r, &p3);

    JITVisitor jit;

    compiled fn = jit.jit(&m);
    
    double inputs[] = { 10.0, 25.0, 10.0 };
    double res = fn(inputs);
    
    std::cout << res << std::endl;

    return 0;
}