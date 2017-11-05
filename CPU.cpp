#include <iostream>
#include "Stack.h"
#include "CPU.h"
#include "assembler.h"

/*
#define PROG_SIZE 1000


typedef double StackElem_t;
typedef int prog_ad;

struct CPU {
    CStack<StackElem_t> stack;
    CStack<prog_ad> call_st;
    StackElem_t ax = 0;
    StackElem_t bx = 0;
    StackElem_t cx = 0;
    int buffer[PROG_SIZE];

};

void CPU_init(CPU *cpu);

bool CPU_Load_prog(const char *filename, CPU *cpu);

int CPU_calc_sum(CPU *cpu);
*/

//long size_f(FILE *text_f);

int main(int argc, char *argv[]) {
    CPU cpu = {0};
    std::cout << argv[1] << std::endl << argv[2] << std::endl;
    if (assembler(argv[1], argv[2]))
        exit(8);
    CPU_init(&cpu);
    if (CPU_Load_prog(argv[2], &cpu)) {
        exit(7);
    }
    CPU_calc_sum(&cpu);
    StackDestruct(&cpu.stack);

}

void CPU_init(CPU *cpu) {
    StackConstruct(&cpu->stack);
    StackConstruct(&cpu->call_st);
};


int CPU_calc_sum(CPU *cpu) {

#define DEF_CMD(num, name, num_arg, code)               \
            case num:                                   \
            {                                           \
                code                                    \
                break;                                  \
            }
    int pc = 0;

    std::cout << "start" << std::endl;
    while (true) {

        std::cout << pc << ":" << getname(cpu->rom[pc]) << "[" << cpu->call_st.count << "]";
        for (int h = 0; h < cpu->stack.count; h++)
            std::cout << " " <<  cpu->stack.data[h];
        std::cout << std::endl;
        switch (cpu->rom[pc++]) {
#include "commands.h"
        }
    }
#undef DEF_CMD
}

/*
long size_f(FILE *text_f) {
    fseek(text_f, 0, SEEK_END);
    long size = ftell(text_f);
    fseek(text_f, 0, SEEK_SET);
    return size;
}
*/

bool CPU_Load_prog(const char *filename, CPU *cpu) {
    FILE *text_f = fopen(filename, "r");
    int pc = 0;
    while (fscanf(text_f, "%d", &cpu->rom[pc]) != EOF) {
        pc++;
        if (pc > ROM_SIZE) {
            return true;
        }
    }
    fclose(text_f);
    return false;
}



