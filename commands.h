//
// Created by andrew on 30.10.17.
//
#define READ_EL StackElem_t res = 0;                      \
                StackElem_t num_1 = StackPop(&cpu->stack);\
                StackElem_t num_2 = StackPop(&cpu->stack);\

#define SPUSH StackPush(&cpu->stack, res);
#define SPOP StackPop(&cpu->stack)

#define DEST k = buffer[k+1] - 1;

#ifndef CPU_COMMANDS_H
#define CPU_COMMANDS_H

DEF_CMD(1, {StackPush(&cpu->stack, buffer[++k]);})

DEF_CMD(2, {READ_EL res = num_1 + num_2;  SPUSH})

DEF_CMD(3, {READ_EL res = num_1 * num_2; SPUSH})

DEF_CMD(4, {READ_EL res = num_2 - num_1; SPUSH})

DEF_CMD(5, {READ_EL res = num_2 / num_1; SPUSH})

DEF_CMD(6, {std::cout << SPOP << std::endl;})

DEF_CMD(7, {DEST})

DEF_CMD(8, {READ_EL if(num_1 == num_2) DEST else k++;})

DEF_CMD(9, {READ_EL if(num_1 != num_2) DEST else k++;})

DEF_CMD(10, {READ_EL if(num_1 > num_2) DEST else k++;})

DEF_CMD(11, {READ_EL if(num_1 >= num_2) DEST else k++;})

DEF_CMD(12, {READ_EL if(num_1 < num_2) DEST else k++;})

DEF_CMD(13, {READ_EL if(num_1 <= num_2) DEST else k++;})

DEF_CMD(14, {cpu->ax = SPOP;})

DEF_CMD(15, {cpu->bx = SPOP;})

DEF_CMD(16, {cpu->cx = SPOP;})

DEF_CMD(17, {StackPush(&cpu->stack, cpu->ax);})

DEF_CMD(18, {StackPush(&cpu->stack, cpu->bx);})

DEF_CMD(19, {StackPush(&cpu->stack, cpu->cx);})


#endif //CPU_COMMANDS_H
