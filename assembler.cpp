#include <iostream>
#include <cstring>
#include "CPU.h"
#include "assembler.h"


#define DEF_CMD(num, name, num_arg, code)  name,

const char *names[] = {
#include "commands.h"
};

#undef DEF_CMD

/*

const char *names[] = {
 "nop",
 "push",
 "add",
};


 */

#define DEF_CMD(num, name, num_arg, code) num_arg,

int num_args[] = {
#include "commands.h"
};

#undef DEF_CMD

// nop = 0;
// push = 1;
// add = 2;
// mul = 3;
// sub = 4
// div = 5
// end = 6
// jmp = 7
// je = 8
// jne = 9
// ja = 10
// jae = 11
// jb = 12
// jbe = 13
// push ax = 14
// push bx = 15
// push cx = 16
// pop ax = 17
// pop bx = 18
// pop cx = 19

const char* getname(int op) {
    return names[op];
}

bool assembler(const char *filenameIN, const char *filenameOUT) {

    FILE *IN = fopen(filenameIN, "r");
    FILE *OUT = fopen(filenameOUT, "w+");

    if (IN == NULL) {
        std::cout << filenameIN << " not found" << std::endl;
        return true;
    }

    if (OUT == NULL) {
        std::cout << filenameOUT << " failure " << std::endl;
        return true;
    }

    char name[10] = {0};

    std::cout << sizeof(num_args) / sizeof(num_args[0]) << std::endl;

    std::cout << num_args[0] << std::endl;
    std::cout << num_args[1] << std::endl;
    std::cout << num_args[2] << std::endl;
    std::cout << num_args[3] << std::endl;
    std::cout << num_args[4] << std::endl;


    int k = 1;
    int pos = 0;
    int pos_j = 0;
    int labels[10] = {0};

    char buf_reg[10] = {0};
    char *regist = {0};
    int num = 0;


    while (fscanf(IN, "%s", name) != EOF) {
        char* ptr = strchr(name, ':');
        if (ptr) {
            *ptr = '\0';
            labels[atoi(name)] = pos;
        }
            pos++;
    }


    fseek(IN, 0, SEEK_SET);

int pc= 0;

    while (fscanf(IN, "%s", name) != EOF) {
        std::cout << pc << ":" << name;
        if (strchr(name, ':')) {
            fprintf(OUT, "%d\n", NOP);
            std::cout << " " << NOP << std::endl;
            pc++;
            continue;
        }
        int op = find_name(name);
        if (op == -1) {
            return true;
        }
  //      std::cout << num_args[op] << std::endl;
        fprintf(OUT, "%d", op);
        std::cout << " " << op ;
        pc++;
        if (num_args[op]) {
            fscanf(IN, "%s", name);
            char* ptr = strchr(name, '$');
            int number = 0;
            if (ptr) {
                *ptr = '\0';
                number = labels[atoi(name)];
            } else {
                number = atoi(name);
            }
            fprintf(OUT, " %d", number);
            std::cout << " " << number;
            pc++;
        }
        fprintf(OUT, "\n");
        std::cout << std::endl;
    }
    fclose(IN);
    fclose(OUT);
    return false;
}


int find_name(const char *name) {
   // std::cout << name << std::endl;
    for (int op = 0; op < sizeof(names) / sizeof(names[0]); op++) {
        if (!strcasecmp(name, names[op]))
            return op;
    }
    return -1;
}