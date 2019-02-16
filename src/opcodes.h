//
// Created by littles on 16.02.19.
//

#ifndef SYNACOR_OPCODES_H
#define SYNACOR_OPCODES_H

#include <unitypes.h>
#include "memory.h"
#include <vector>

void opcode_processOpCode(uint16_t& pos, std::vector<uint16_t>& codes, Memory& memory);

#endif //SYNACOR_OPCODES_H