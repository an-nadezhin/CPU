#include <iostream>
#include "Stack.cpp"

typedef int elem_t;

FILE *text_f = fopen("newcommands.txt", "rb");

struct CPU {
    CStack str = {0};
};
CPU cpu;

int main() {
    StackConstruct(&cpu.str);

}

elem_t add(CStack *cpu_str) {
    elem_t res = 0;
    elem_t num_1 = StackPop(cpu_str);
    elem_t num_2 = StackPop(cpu_str);

    res = num_1 + num_2;

    return StackPush(cpu_str, res);
}

elem_t mul(CStack *cpu_str) {
    elem_t res = 0;
    elem_t num_1 = StackPop(cpu_str);
    elem_t num_2 = StackPop(cpu_str);

    res = num_1*num_2;

    return StackPush(cpu_str, res);
}

elem_t div(CStack *cpu_str) {
    elem_t res = 0;
    elem_t num_1 = StackPop(cpu_str);
    elem_t num_2 = StackPop(cpu_str);

    res = num_2/num_1;

    return StackPush(cpu_str, res);
}


elem_t sub(CStack *cpu_str) {
    elem_t res = 0;
    elem_t num_1 = StackPop(cpu_str);
    elem_t num_2 = StackPop(cpu_str);

    res = num_1 - num_2;

    return StackPush(cpu_str, res);
}

