#include <iostream>
#include "Stack.cpp"

typedef int elem_t;

FILE *text_f = fopen("newcommands.txt", "rb");

#define read_el elem_t res = 0;                      \
                elem_t num_1 = StackPop(&cpu->stack);\
                elem_t num_2 = StackPop(&cpu->stack);\

struct CPU {
    CStack stack;
    elem_t num_R;
    elem_t num_A;
    elem_t num_B;
};


int calc_sum(CPU *str);

void add(CPU *cpu);

void mul(CPU *cpu);

void div(CPU *cpu);

void sub(CPU *cpu);

void sub(CPU *cpu);

void out(CPU *cpu);

void push(CPU *cpu, int num);

int main() {
    CPU str = {0};
    elem_t num = 0;
    StackConstruct(&str.stack);
    calc_sum(&str);
    StackDestruct(&str.stack);
    fclose(text_f);
}

int calc_sum(CPU *cpu) {
    cpu->num_R = 0;
    cpu->num_B = 0;
    cpu->num_A = 0;

    int *buffer = NULL;
    fseek(text_f, 0, SEEK_END);
    long size = ftell(text_f);
    fseek(text_f, 0, SEEK_SET);
    buffer = (int *) calloc(size + 1, sizeof(elem_t));
    for (int i = 0; i < size; i++)
        fscanf(text_f, "%d", &buffer[i]);
    for (int k = 0; k < size; k++) {
        switch (buffer[k]) {
            case 1: {
                push(cpu, buffer[++k]);
                break;
            }
            case 2: {
                add(cpu);
                break;
            }
            case 3: {
                mul(cpu);
                break;
            }
            case 4: {
                sub(cpu);
                break;
            }
            case 5: {
                div(cpu);
                break;
            }
            case 6: {
                out(cpu);
                break;
            }
            case
        }
    }
}


void add(CPU *cpu) {
    read_el
    res = num_1 + num_2;

    StackPush(&cpu->stack, res);
}

void mul(CPU *cpu) {
    read_el
    res = num_1 * num_2;

    StackPush(&cpu->stack, res);
}

void div(CPU *cpu) {
    read_el
    res = num_2 / num_1;

    StackPush(&cpu->stack, res);
}

void sub(CPU *cpu) {
    read_el
    res = num_2 - num_1;

    StackPush(&cpu->stack, res);
}

void out(CPU *cpu) {
    std::cout << StackPop(&cpu->stack) << std::endl;
}

void push(CPU *cpu, int num) {
    StackPush(&cpu->stack, num);
}
