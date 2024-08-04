#pragma once

#include <vector>

typedef double (*compiled)(double*);

class Emitter {
    std::vector<char> instructions;

public:
    void movesd_reg_memory(char reg, char displacement);
    void movesd_memory_reg(char reg, char displacement);
    void movesd_reg_reg(char src, char dest);
    void mulsd(char src, char dest);
    void addsd(char src, char dest);
    void subsd(char src, char dest);
    void divsd(char src, char dest);
    compiled compile();
};