//
// Created by andrew on 05.11.17.
//

#ifndef CPU_STACK_H
#define CPU_STACK_H

#include <iostream>
#include <cassert>
#include <math.h>

#define NMAX 100

const double POISON = atan(M_PI);

//typedef double StackElem_t;

#define ASSERT_OK() if(!StackOK(str1))        \
                        {                     \
                        assert(!"!!!");       \
                        }

template <typename T>
class CStack {
public:
    int o = 0;
    double canary1 = POISON;
    T *data;
    int count;
    T hash_sum;
    double canary2 = POISON;
};

//template <typename T>
//void StackDump(CStack<T> *str1);

template <typename T>
void StackConstruct(CStack<T> *str1);

template <typename T>
int StackPush(CStack<T> *str1, T num);

template <typename T>
T StackPop(CStack<T> *str1);

template <typename T>
void StackDestruct(CStack<T> *str1);

template <typename T>
bool StackOK(CStack<T> *str1);

template <typename T>
T hash(CStack<T> *str1);

//----------------------------------------------------------
//! Create Stack
//!
//!@param [IN] str1 pointer on struct stack
//!
//!@note in case of error assert
//!
//----------------------------------------------------------

template <typename T>
void StackConstruct(CStack<T> *str1) {
    str1->count = 0;

    str1->data = (T*) calloc(sizeof(str1->data), NMAX + 3);
    if (str1->data == NULL)
        exit(2);
  //  str1->data[0] = POISON;
  //  str1->data[NMAX + 2] = POISON;
    //   for(int h = 0; h < NMAX + 3; h++)
    //       std::cout << str1->data[h] << std::endl;
  //  str1->data++ ;
    str1->hash_sum = hash(str1);
    //  std::cout << str1->data[-1] << std::endl;
    ASSERT_OK()
}

//----------------------------------------------------------
//! Push element in Stack
//!
//!@param [IN] str1 pointer on struct stack
//!@param [OUT] value element which we push in stack
//!
//!@return code of error
//!
//----------------------------------------------------------

template <typename T>
int StackPush(CStack<T> *str1, T value) {
    ASSERT_OK()
    if (str1->count < NMAX) {
        str1->data[str1->count++] = value;
        str1->hash_sum = hash(str1);
    } else {
        std::cout << "Stack is full" << std::endl;
        return 1;
    }
    ASSERT_OK()
    return 0;
}

//-------------------------------------------------------------
//! Return upper element in Stack
//!
//!@param [IN] str1 pointer on struct stack
//!
//!@return upper element
//!
//-------------------------------------------------------------

template <typename T>
T StackPop(CStack<T> *str1) {

    T elem = 0;
    ASSERT_OK()
    if (str1->count > 0) {
        elem = str1->data[--str1->count];
        str1->hash_sum = hash(str1);
        return elem;
    } else
        std::cout << "Stack is end" << std::endl;
    ASSERT_OK()
}

//----------------------------------------------------------
//! Destruct Stack
//!
//!@param [IN] str1 pointer on struct stack
//!
//!@note in case of error assert
//!
//----------------------------------------------------------

template <typename T>
void StackDestruct(CStack<T> *str1) {
    ASSERT_OK()
    str1->count = -1;
    free(str1->data);
}

//----------------------------------------------------------
//! function which check errors
//!
//!@param [IN] str1 pointer on struct stack
//!
//!@return 1 if find error or 0 if error not found
//!
//----------------------------------------------------------

template <typename T>
bool StackOK(CStack<T> *str1) {
    return str1->count >= 0
           && str1->data
           && str1->count < NMAX
           && str1->canary1 == POISON
           && str1->canary2 == POISON
      //     && str1->data[-1] == POISON
      //     && str1->data[NMAX + 1] == POISON
           && str1->hash_sum == hash(str1);
}

//----------------------------------------------------------
//! function which print information in log file
//!
//!@param [IN] str1 pointer on struct stack
//!
//----------------------------------------------------------
/*
template <typename T>
void StackDump(CStack<T> *str1) {

    fprintf(f, "Stack (ERROR!!!)\n");
    fprintf(f, "count = %d\n", str1->count);
    fprintf(f, "data[NMAX] %p = \n", str1->data);
    for (int i = -1; i <= NMAX + 1; i++)
        fprintf(f, "[%d] = %f\n", i, (double) str1->data[i]);
    fflush(f);
}
*/
//----------------------------------------------------------
//! hash function which calculate sum all elements
//!
//!@param [IN] str1 pointer on struct stack
//!
//!@return sum all elements
//!
//----------------------------------------------------------

template <typename T>
T hash(CStack<T> *str1) {

    T sum = 0;

    for (int i = 0; i < NMAX; i++)
        sum += str1->data[i + 1];
    sum += str1->count;
    return sum;
}


#endif //CPU_STACK_H
