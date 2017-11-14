#include "CPU.h"

int main(int argc, char *argv[]) {
    CPU cpu = {0};
    if (assembler(argv[1], argv[2]))
        std::cout << "error in opening file" << std::endl;
    CPU_init(&cpu);
    if (CPU_Load_prog(argv[2], &cpu)) {
        std::cout << "file too large" << std::endl;
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

    while (true) {
        switch ((int) cpu->rom[pc++]) {
#include "commands.h"
        }
    }
#undef DEF_CMD
}

bool CPU_Load_prog(const char *filename, CPU *cpu) {
    FILE *text_f = fopen(filename, "r");
    int pc = 0;
    while (fscanf(text_f, "%lg", &cpu->rom[pc]) != EOF) {
        pc++;
        if (pc > ROM_SIZE) {
            return true;
        }
    }
    fclose(text_f);
    return false;
}

