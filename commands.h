//
// Created by andrew on 30.10.17.
//
#define READ_EL StackElem_t res = 0;                      \
                StackElem_t num_1 = StackPop(&cpu->stack);\
                StackElem_t num_2 = StackPop(&cpu->stack);\

#define SPUSH StackPush(&cpu->stack, res);
#define SPOP StackPop(&cpu->stack)

#define DEST pc = cpu->rom[pc];


DEF_CMD(NOP, "nop", 0, {})

DEF_CMD(PUSH, "push", 1, {StackPush(&cpu->stack, (StackElem_t) cpu->rom[pc++]);})

DEF_CMD(ADD, "add", 0, {READ_EL res = num_2 + num_1;  SPUSH})

DEF_CMD(MUL, "mul", 0, {READ_EL res = num_2 * num_1; SPUSH})

DEF_CMD(SUB, "sub", 0, {READ_EL res = num_2 - num_1; SPUSH})

DEF_CMD(DIV, "div", 0, {READ_EL res = num_2 / num_1; SPUSH})

DEF_CMD(POW, "pow", 0, {READ_EL res = pow(num_2, num_1); SPUSH})

DEF_CMD(SQRT, "sqrt", 0, {StackElem_t arg = SPOP; StackPush(&cpu->stack, sqrt(arg));})

DEF_CMD(OUT, "out", 0, {std::cout << SPOP << std::endl;})

DEF_CMD(JMP, "jmp", 1, {DEST})

DEF_CMD(JE, "je", 1, {READ_EL if(num_2 == num_1) DEST else pc++;})

DEF_CMD(JNE, "jne", 1, {READ_EL if(num_2 != num_1) DEST else pc++;})

DEF_CMD(JA, "ja", 1, {READ_EL if(num_2 > num_1) DEST else pc++;})

DEF_CMD(JAE, "jae", 1, {READ_EL if(num_2 >= num_1) DEST else pc++;})

DEF_CMD(JB, "jb", 1, {READ_EL if(num_2 < num_1) DEST else pc++;})

DEF_CMD(JBE, "jbe", 1, {READ_EL if(num_2 <= num_1) DEST else pc++;})

DEF_CMD(POP_AX, "pop_ax", 0, {cpu->ax = SPOP;})

DEF_CMD(POP_BX, "pop_bx", 0, {cpu->bx = SPOP;})

DEF_CMD(POP_CX, "pop_cx", 0, {cpu->cx = SPOP;})

DEF_CMD(POP_DX, "pop_dx", 0, {cpu->dx = SPOP;})

DEF_CMD(PUSH_AX, "push_ax", 0, {StackPush(&cpu->stack, cpu->ax);})

DEF_CMD(PUSH_BX, "push_bx", 0, {StackPush(&cpu->stack, cpu->bx);})

DEF_CMD(PUSH_CX, "push_cx", 0, {StackPush(&cpu->stack, cpu->cx);})

DEF_CMD(PUSH_DX, "push_dx", 0, {StackPush(&cpu->stack, cpu->dx);})

DEF_CMD(CALL, "call", 1, {StackPush(&cpu->call_st, pc + 1); DEST})

DEF_CMD(RET, "ret", 0, {pc = StackPop(&cpu->call_st);})

DEF_CMD(LD, "ld", 0, {int a = (int) SPOP; StackPush(&cpu->stack, cpu->ram[a]);})

DEF_CMD(ST, "st", 0, {StackElem_t value = SPOP; int a = (int) SPOP; cpu->ram[a] = value;})

DEF_CMD(HALT, "halt", 0, {return 0;})

DEF_CMD(IN, "in", 0, {int in_num = 0; std::cout << "VVedite chislo : "; std::cin >> in_num; std::cout << std::endl; StackPush(&cpu->stack, (StackElem_t) in_num);})

DEF_CMD(END, "end", 0, std::cout << "end" << std::endl;)

DEF_CMD(NO_ROOTS, "no_roots", 0, std::cout << "no roots" << std::endl;)

DEF_CMD(INF, "inf", 0, std::cout << "inf" << std::endl;)

DEF_CMD(PUSH_DEEP, "push_deep", 1, {int dep = cpu->rom[pc++]; StackElem_t res = *get_elem_ptr(&cpu->stack, dep); SPUSH})

DEF_CMD(POP_DEEP, "pop_deep", 1, {int dep = cpu->rom[pc++]; StackElem_t  nu = SPOP; *get_elem_ptr(&cpu->stack, dep) = nu;})

DEF_CMD(DROP, "drop", 1, {int miss = cpu->rom[pc++]; StackElem_t res = SPOP; while(miss-- > 0) SPOP; SPUSH})
