//
// Created by littles on 16.02.19.
//

#ifndef SYNACOR_OPCODES_H
#define SYNACOR_OPCODES_H

#include "memory.h"
#include <vector>

void opcode_processOpCode(unsigned short int& pos, const std::vector<unsigned short int>& codes, Memory& memory);

#endif //SYNACOR_OPCODES_H