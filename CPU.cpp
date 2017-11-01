#include <iostream>
#include "Stack.cpp"
#include "/home/andrew/CPU/assembler.cpp"

struct CPU {
    CStack stack;
    CStack call_st;
    StackElem_t ax;
    StackElem_t bx;
    StackElem_t cx;
};

int calc_sum(CPU *str, FILE* text_f);


long size_f(FILE* text_f);

int main() {
    CPU str = {0};
    recode();
    FILE* text_f = fopen("newcommands.txt", "r");
    StackConstruct(&str.stack);
    calc_sum(&str, text_f);
    StackDestruct(&str.stack);
    fclose(text_f);
}


int calc_sum(CPU *cpu, FILE* text_f) {

    int *buffer = {0};

    long size = size_f(text_f);

    buffer = (int *) calloc(size + 1, sizeof(int));
    for (int t = 0; t < size; t++) {
        fscanf(text_f, "%d", &buffer[t]);
  //      std::cout << buffer[t] << std::endl;

    }
#define DEF_CMD(num, code)                              \
            case num:                                   \
            {                                           \
                code                                    \
                break;                                  \
            }
    for (int k = 0; k < size; k++) {
 //       std::cout << buffer[k] << std::endl;
        switch (buffer[k]) {
#include </home/andrew/CPU/commands.h>
        }
    }
#undef DEF_CMD
}


long size_f(FILE* text_f) {
    fseek(text_f, 0, SEEK_END);
    long size = ftell(text_f);
    fseek(text_f, 0, SEEK_SET);
    return size;
}




