//
// Created by xcite on 10/4/2023.
//

#ifndef STACK_STACKED_H
#define STACK_STACKED_H

#include <iostream>

typedef enum {
    S_no = 0,
    S_yes,
    S_full,
    S_empty

} Status;
typedef struct {
    void **size;
    int pointer;
    int max;
} Stack;

Stack *CreateStack(int size, Status *retval);

Stack *DestroyStack(Stack *stack, Status *retval);

Status PushElement(Stack *stack, void *element);

Status PopElement(Stack *stack, void *re);


#endif //STACK_STACKED_H
