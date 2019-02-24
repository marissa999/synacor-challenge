//
// Created by littles on 16.02.19.
//

#ifndef SYNACOR_MEMORY_H
#define SYNACOR_MEMORY_H

#include <stack>

class Memory{
    private:
        unsigned short int mem_register[8] = {};
    public:
        Memory();
        ~Memory();
        unsigned short int* returnValue(unsigned short int* a);
        void writeToRegister(unsigned short int register_address, unsigned short int value);
        std::stack<unsigned short int> stack;
        unsigned short int memory[32768] = {};
};

#endif //SYNACOR_MEMORY_H