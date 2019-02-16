//
// Created by littles on 16.02.19.
//

#include "opcodes.h"

#include <iostream>

// 0 - halt: stop execution and terminate the program
void opcode_halt(uint16_t& pos, Memory& memory){
    // nothing to implement
}

// 1 - set: set register <a> to the value of <b>
void opcode_set(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b){

    pos += 2;
}

// 2 - push: push <a> onto the stack
void opcode_push(uint16_t& pos, Memory& memory, uint16_t a){

    pos += 1;
}

// 3 - pop: remove the top element from the stack and write it into <a>; empty stack = error
void opcode_pop(uint16_t& pos, Memory& memory, uint16_t a){

    pos += 1;
}

// 4 -  eq: set <a> to 1 if <b> is equal to <c>; set it to 0 otherwise
void opcode_eq(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b, uint16_t c){

    pos += 4;
}

// 5 - gt: set <a> to 1 if <b> is greater than <c>; set it to 0 otherwise
void opcode_gt(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b, uint16_t c){

    pos += 4;
}

// 6 - jmp: jump to <a>
void opcode_jmp(uint16_t& pos, Memory& memory, uint16_t a){
    pos = a;
}

// 7: jt - if <a> is nonzero, jump to <b>
void opcode_jt(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b){

    pos += 3;
}

// 8: jf - if <a> is zero, jump to <b>
void opcode_jf(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b){

    pos += 3;
}

// 9: add - assign into <a> the sum of <b> and <c> (uint16_t& pos, Memory& memory, modulo 32768)
void opcode_add(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b, uint16_t c){

    pos += 4;
}

// 10: mult - store into <a> the product of <b> and <c> (uint16_t& pos, Memory& memory, modulo 32768)
void opcode_mult(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b, uint16_t c){

    pos += 4;
}

// 11: mod - store into <a> the remainder of <b> divided by <c>
void opcode_mod(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b, uint16_t c){

    pos += 4;
}

// 12: and - stores into <a> the bitwise and of <b> and <c>
void opcode_and(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b, uint16_t c){

    pos += 4;
}

// 13: or - stores into <a> the bitwise or of <b> and <c>
void opcode_or(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b, uint16_t c){

    pos += 4;
}

// 14: not - stores 15-bit bitwise inverse of <b> in <a>
void opcode_not(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b){

    pos += 3;
}

// 15: rmem - read memory at address <b> and write it to <a>
void opcode_rmem(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b){

    pos += 3;
}

// 16: wmem - write the value from <b> into memory at address <a>
void opcode_wmem(uint16_t& pos, Memory& memory, uint16_t a, uint16_t b){

    pos += 3;
}

// 17: call - write the address of the next instruction to the stack and jump to <a>
void opcode_call(uint16_t& pos, Memory& memory, uint16_t a){

    pos += 2;
}

// 18: ret - remove the top element from the stack and jump to it; empty stack = halt
void opcode_ret(uint16_t& pos, Memory& memory){

}

// 19: out - write the character represented by ascii code <a> to the terminal
void opcode_out(uint16_t& pos, Memory& memory, uint16_t a){
    std::cout << static_cast<char>(a & 0xFF);
    pos += 2;
}

// 20: in - read a character from the terminal and write its ascii code to <a>; it can be assumed that once input starts, it will continue until a newline is encountered; this means that you can safely read whole lines from the keyboard and trust that they will be fully read
void opcode_in(uint16_t& pos, Memory& memory, uint16_t a){

    pos += 2;
}

// 21: noop - no operation
void opcode_noop(uint16_t& pos, Memory& memory){
    pos += 1;
}

void opcode_processOpCode(uint16_t& pos, std::vector<uint16_t>& codes, Memory& memory){
    uint16_t a, b, c;
    uint16_t opcode = codes[pos];
    if (opcode == 2
    || opcode == 3
    || opcode == 6
    || opcode == 17
    || opcode == 19
    || opcode == 21
    || opcode == 21){
        a = codes[pos + 1];
    }
    if (opcode == 1
    || opcode == 7
    || opcode == 8
    || opcode == 14
    || opcode == 15
    || opcode == 16){
        a = codes[pos + 1];
        b = codes[pos + 2];
    }
    if (opcode == 4
    || opcode == 5
    || opcode == 9
    || opcode == 10
    || opcode == 11
    || opcode == 12
    || opcode == 13){
        a = codes[pos + 1];
        b = codes[pos + 2];
        c = codes[pos + 3];
    }

    switch (opcode){
        case 0:
            opcode_halt(pos, memory);
            break;
        case 1:
            opcode_set(pos, memory, a, b);
            break;
        case 2:
            opcode_push(pos, memory, a);
            break;
        case 3:
            opcode_pop(pos, memory, a);
            break;
        case 4:
            opcode_eq(pos, memory, a, b, c);
            break;
        case 5:
            opcode_gt(pos, memory, a, b, c);
            break;
        case 6:
            opcode_jmp(pos, memory, a);
            break;
        case 7:
            opcode_jt(pos, memory, a, b);
            break;
        case 8:
            opcode_jf(pos, memory, a, b);
            break;
        case 9:
            opcode_add(pos, memory, a, b, c);
            break;
        case 10:
            opcode_mult(pos, memory, a, b, c);
            break;
        case 11:
            opcode_mod(pos, memory, a, b, c);
            break;
        case 12:
            opcode_and(pos, memory, a, b, c);
            break;
        case 13:
            opcode_or(pos, memory, a, b, c);
            break;
        case 14:
            opcode_not(pos, memory, a, b);
            break;
        case 15:
            opcode_rmem(pos, memory, a, b);
            break;
        case 16:
            opcode_wmem(pos, memory, a, b);
            break;
        case 17:
            opcode_call(pos, memory, a);
            break;
        case 18:
            opcode_ret(pos, memory);
            break;
        case 19:
            opcode_out(pos, memory, a);
            break;
        case 20:
            opcode_in(pos, memory, a);
            break;
        case 21:
            opcode_noop(pos, memory);
            break;
        default:
            break;
    }
}