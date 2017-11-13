//
// Created by andrew on 05.11.17.
//

#ifndef CPU_CPU_H
#define CPU_CPU_H

#include "Stack.h"
#include <math.h>



#define DEF_CMD(num, name, num_arg, code) num,

    enum {
#include "commands.h"
    };

#undef DEF_CMD


#define ROM_SIZE (1 << 10)
#define RAM_SIZE (1 << 10)

typedef double StackElem_t;
typedef int prog_ad;

struct CPU {
    CStack<StackElem_t> stack;
    CStack<prog_ad> call_st;
    StackElem_t ax = 0;
    StackElem_t bx = 0;
    StackElem_t cx = 0;
    StackElem_t dx = 0;
    StackElem_t rom[ROM_SIZE];
    StackElem_t ram[RAM_SIZE];

};

void CPU_init(CPU *cpu);

bool CPU_Load_prog(const char *filename, CPU *cpu);

int CPU_calc_sum(CPU *cpu);

#endif //CPU_CPU_H
