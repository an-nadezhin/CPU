#include <iostream>
#include <cstring>

FILE *IN = fopen("/home/andrew/CPU/cmake-build-debug/comands.txt", "r");
FILE *OUT = fopen("/home/andrew/CPU/cmake-build-debug/newcommands.txt", "w+");


int recode();



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


int recode() {

    int k = 1;
    int pos = 0;
    int pos_j = 0;
    int labels[10] = {0};
    char buffer[10] = {0};
    char buf_reg[10] = {0};
    int num = 0;

    while (fscanf(IN, "%s", buffer) != EOF) {
        if (strchr(buffer, ':')) {
            labels[k++] = pos;
        }
        pos++;

    }

    fseek(IN, 0, SEEK_SET);

    while (fscanf(IN, "%s", buffer) != EOF) {

        if (!strcmp(buffer, "push")) {
            fscanf(IN, "%s", buf_reg);
            if (!strcmp(buf_reg, "ax")) {
                fprintf(OUT, "14\n");
                memset(buffer, 0, 10);
              //  fprintf(OUT, "%s\n", buf_reg);
                memset(buf_reg, 0, 10);
                continue;
            }
            if (!strcmp(buf_reg, "bx")) {
                fprintf(OUT, "15\n");
                memset(buffer, 0, 10);
              //  fprintf(OUT, "%s\n", buf_reg);
                memset(buf_reg, 0, 10);
                continue;
            }
            if (!strcmp(buf_reg, "cx")) {
                fprintf(OUT, "16\n");
                memset(buffer, 0, 10);
             //   fprintf(OUT, "%s\n", buf_reg);
                memset(buf_reg, 0, 10);
                continue;
            }
            fprintf(OUT, "1 ");
            memset(buffer, 0, 10);
            fprintf(OUT, "%s\n", buf_reg);
            memset(buf_reg, 0, 10);
        }

     //   if(!strcmp(buffer, "call"))

        if (!strcmp(buffer, "pop")) {
            fscanf(IN, "%s", buf_reg);
            if (!strcmp(buf_reg, "ax")) {
                fprintf(OUT, "17\n");
               // fprintf(OUT, "%s\n", buf_reg);
                memset(buffer, 0, 10);
                memset(buf_reg, 0, 10);
                continue;
            }
            if (!strcmp(buf_reg, "bx")) {
                fprintf(OUT, "18\n");
                memset(buf_reg, 0, 10);
          //      fprintf(OUT, "%s\n", buffer);
                memset(buffer, 0, 10);
                continue;
            }
            if (!strcmp(buf_reg, "cx")) {
                fprintf(OUT, "19\n");
                memset(buf_reg, 0, 10);
           //     fprintf(OUT, "%s\n", buffer);
                memset(buffer, 0, 10);
                continue;
            }
        }


        if (!strcmp(buffer, "add")) {
            fprintf(OUT, "2\n");
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "mul")) {
            fprintf(OUT, "3\n");
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "sub")) {
            fprintf(OUT, "4\n");
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "div")) {
            fprintf(OUT, "5\n");
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "end")) {
            fprintf(OUT, "6\n");
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "jmp")) {
            fprintf(OUT, "7 ");
            memset(buffer, 0, 10);
            fscanf(IN, "%s", buffer);
            int l = atoi(buffer);
            fprintf(OUT, "%d\n", labels[l]);
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "je")) {
            fprintf(OUT, "8 ");
            memset(buffer, 0, 10);
            fscanf(IN, "%s", buffer);
            int l = atoi(buffer);
            fprintf(OUT, "%d\n", labels[l]);
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "jne")) {
            fprintf(OUT, "9 ");
            memset(buffer, 0, 10);
            fscanf(IN, "%s", buffer);
            int l = atoi(buffer);
            fprintf(OUT, "%d\n", labels[l]);
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "ja")) {
            fprintf(OUT, "10 ");
            memset(buffer, 0, 10);
            fscanf(IN, "%s", buffer);
            int l = atoi(buffer);
            fprintf(OUT, "%d\n", labels[l]);
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "jae")) {
            fprintf(OUT, "11 ");
            memset(buffer, 0, 10);
            fscanf(IN, "%s", buffer);
            int l = atoi(buffer);
            fprintf(OUT, "%d\n", labels[l]);
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "jb")) {
            fprintf(OUT, "12 ");
            memset(buffer, 0, 10);
            fscanf(IN, "%s", buffer);
            int l = atoi(buffer);
            fprintf(OUT, "%d\n", labels[l]);
            memset(buffer, 0, 10);
        }
        if (!strcmp(buffer, "jbe")) {
            fprintf(OUT, "13 ");
            memset(buffer, 0, 10);
            fscanf(IN, "%s", buffer);
            int l = atoi(buffer);
            fprintf(OUT, "%d\n", labels[l]);
            memset(buffer, 0, 10);
        }
    }
    fclose(IN);
    fclose(OUT);
}



