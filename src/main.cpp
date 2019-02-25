//
// Created by littles on 16.02.19.
//

#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<unsigned short int> initCodes(Memory& memory){
    std::vector<unsigned short int> codes;
    // init buffer
    char* buffer;
    // init length
    int length;
    // init input file stream
    std::ifstream ifs ("challenge.bin", std::ifstream::binary);
    // if we were able to init ifs
    if (ifs) {
        // get length of file
        ifs.seekg(0, ifs.end);
        length = ifs.tellg();
        ifs.seekg(0, ifs.beg);

        // make char buffer
        buffer = new char[length];
        // read every byte
        ifs.read(buffer, length);
        // close ifs
        ifs.close();
    } else {
        std::cout << "Could not open the binary 'challenge.bin'. Stop!" << std::endl;
        exit(0);
    }
    // make 8 bits to 16 bit
    for(int i = 0; i < length; i += 2)
        memory.memory[(i >> 1)] = (static_cast<unsigned short int>(buffer[i] & 0xff)) | (static_cast<unsigned short int>(buffer[i + 1] << 8));
    return codes;
}

int main (const int argc, const char *argv[]){
    // init memory
    Memory memory;

    unsigned short int pos = 0;

    // read opcodes and operands
    initCodes(memory);
    // exectue while opcode isnt 0

    while(memory.memory[pos] != 0){
        processOpCode(pos, memory);
    }

    return 0;
}