#include "emitter.h"
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <cstring>

void Emitter::movesd_reg_memory(char reg, char displacement)
{
    char prefix = 0xf2;
    char opcode_prefix = 0x0f;
    char opcode = 0x11;
    char mod = 0x47 | reg << 3; // using the address at rdi + given displacement

    instructions.push_back(prefix);
    instructions.push_back(opcode_prefix);
    instructions.push_back(opcode);
    instructions.push_back(mod);
    instructions.push_back(displacement);
}

void Emitter::movesd_memory_reg(char reg, char displacement)
{
    char prefix = 0xf2;
    char opcode_prefix = 0x0f;
    char opcode = 0x10;
    char mod = 0x47 | reg << 3; // using the address at rdi + given displacement

    instructions.push_back(prefix);
    instructions.push_back(opcode_prefix);
    instructions.push_back(opcode);
    instructions.push_back(mod);
    instructions.push_back(displacement);
}

void Emitter::movesd_reg_reg(char src, char dest)
{
    char prefix = 0xf2;
    char opcode_prefix = 0x0f;
    char opcode = 0x11;
    char mod = 0xc0 | src << 3 | dest;

    instructions.push_back(prefix);
    instructions.push_back(opcode_prefix);
    instructions.push_back(opcode);
    instructions.push_back(mod);
}

void Emitter::addsd(char src, char dest)
{
    char prefix = 0xf2;
    char opcode_prefix = 0x0f;
    char opcode = 0x58;
    char mod = 0xc0 | dest << 3 | src;

    instructions.push_back(prefix);
    instructions.push_back(opcode_prefix);
    instructions.push_back(opcode);
    instructions.push_back(mod);
}

void Emitter::subsd(char src, char dest)
{
    char prefix = 0xf2;
    char opcode_prefix = 0x0f;
    char opcode = 0x5c;
    char mod = 0xc0 | dest << 3 | src;

    instructions.push_back(prefix);
    instructions.push_back(opcode_prefix);
    instructions.push_back(opcode);
    instructions.push_back(mod);
}

void Emitter::mulsd(char src, char dest)
{
    char prefix = 0xf2;
    char opcode_prefix = 0x0f;
    char opcode = 0x59;
    char mod = 0xc0 | dest << 3 | src;

    instructions.push_back(prefix);
    instructions.push_back(opcode_prefix);
    instructions.push_back(opcode);
    instructions.push_back(mod);
}

void Emitter::divsd(char src, char dest)
{
    char prefix = 0xf2;
    char opcode_prefix = 0x0f;
    char opcode = 0x5e;
    char mod = 0xc0 | dest << 3 | src;

    instructions.push_back(prefix);
    instructions.push_back(opcode_prefix);
    instructions.push_back(opcode);
    instructions.push_back(mod);
}

compiled Emitter::compile()
{
    int size = instructions.size() + 1;

    void* mem = mmap(nullptr, size, PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (mem == MAP_FAILED) {
        perror("mmap");
        return nullptr;
    }

    char* code = (char*) malloc(size);

    for (int i = 0; i < size - 1; i++) {
        code[i] = instructions[i];
    }

    code[size - 1] = 0xc3;

    std::memcpy(mem, code, size);

    return (compiled) mem;
}