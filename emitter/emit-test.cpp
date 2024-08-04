#include "emitter.h"
#include <iostream>

int main()
{
    Emitter e;
    e.movesd_memory_reg(0, 0);
    e.movesd_memory_reg(1, 8);
    e.addsd(1, 1);
    e.addsd(1, 0);
    compiled fn = e.compile();

    double* inputs;
    inputs[0] = 2.5;
    inputs[1] = 2.5;

    double res = fn(inputs);

    std::cout << res << std::endl;

    return 0;
}