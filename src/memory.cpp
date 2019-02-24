//
// Created by littles on 16.02.19.
//

#include "memory.h"
#include <iostream>

Memory::Memory() {
}

Memory::~Memory() {
}

unsigned short int* Memory::returnValue(unsigned short int* a){
    // if a not a register return the value
    if (*a < 32768)
        return a;

    // if a a register return the value of the register
    if (*a >= 32768 && *a <= 32775)
        return mem_register + (*a - 32768);

    return 0;
}

void Memory::writeToRegister(unsigned short int register_address, unsigned short int value){
//    std::cout << " - wrote to " << register_address << " value " << value;
    this->mem_register[register_address] = value;
}
