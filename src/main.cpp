//
// Created by littles on 16.02.19.
//

#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<unsigned short int> initCodes(){
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
        std::cout << "Couldn't open file. Stop!" << std::endl;
        exit(0);
    }
    // make 8 bits to 16 bit
    for(int i = 0; i < length; i += 2){
        codes.push_back((static_cast<unsigned short int>(buffer[i] & 0xff)) | (static_cast<unsigned short int>(buffer[i + 1] << 8)));
    }
    return codes;
}

int main (const int argc, const char *argv[]){

    std::cout << "Starting emulator..." << std::endl;
    std::cout << "Reading binary..." << std::endl;

    // init memory
    Memory memory;
    unsigned short int pos = 0;

    // read opcodes and operands
    const std::vector<unsigned short int> codes = initCodes();
    std::cout << "Binary fully loaded..." << std::endl;

    std::cout << "Starting emulator..." << std::endl;
    // exectue while opcode isnt 0
    while(codes[pos] != 0){
        opcode_processOpCode(pos, codes, memory);
    }

    return 0;
}