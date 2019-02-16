//
// Created by littles on 16.02.19.
//

#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>

void initCodes(std::vector<uint16_t>& codes){
    // init buffer
    char *buffer;
    // init length
    int length;
    // init input file stream
    std::ifstream ifs ("challenge.bin", std::ifstream::binary);
    // if we were able to init ifs
    if (ifs) {
        ifs.seekg(0, ifs.end);
        length = ifs.tellg();
        ifs.seekg(0, ifs.beg);

        buffer = new char[length];
        ifs.read(buffer, length);
        ifs.close();
    } else {
        std::cout << "Couldn't open file. Stop!" << std::endl;
        exit(0);
    }
    // make 8 bits to 16 bit
    for(int i = 0; i < length; i += 2){
        codes.push_back((static_cast<uint16_t>(buffer[i + 1] << 8)) | (static_cast<uint16_t>(buffer[i])));
    }
}

int main (const int argc, const char *argv[])
{
    // init memory
    Memory memory;
    std::vector<uint16_t> codes;
    uint16_t pos = 0;

    initCodes(codes);

    while(codes[pos] != 0){
        opcode_processOpCode(pos, codes, memory);
    }

    return 0;
}