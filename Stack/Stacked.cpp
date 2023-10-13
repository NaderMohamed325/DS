#include "Stacked.h"
#include <cstdio>
#include <cstdlib>

Stack *CreateStack(int size, Status *retval) {
    Stack *my_stack = (Stack *)malloc(sizeof(Stack)); // Allocate memory for the stack
    if (my_stack == NULL) {
        printf("Cannot Create Stack!\n");
        *retval = S_no;
    } else {
        my_stack->max = size;
        my_stack->size = (void **)malloc(size * sizeof(void *)); // Allocate memory for the stack elements
        my_stack->pointer = -1;
        if (my_stack->size == NULL) {
            free(my_stack);
            printf("Cannot Create Stack 2!\n");
            *retval = S_no;
        } else {
            printf("Done\n");
            *retval = S_yes;
        }
    }
    return my_stack;
}

Stack *DestroyStack(Stack *stack, Status *retval) {
    if (stack == NULL) {
        printf("Cannot Destroy Stack!\n");
        *retval = S_no;
    } else {
        if (stack->size != NULL) {
            free(stack->size); // Free the memory allocated for stack elements
        }
        free(stack); // Free the memory allocated for the stack structure
        *retval = S_yes;
    }
    return NULL; // Return NULL after destroying the stack
}

Status PushElement(Stack *stack, void *element) {
    if (stack == NULL || element == NULL) {
        printf("Cannot push the element\n");
        return S_no;
    } else {
        if (stack->pointer == stack->max - 1) {
            printf("Stack is full\n");
            return S_full;
        } else {
            stack->pointer++;
            stack->size[stack->pointer] = element;
            printf("Done\n");
            return S_yes;
        }
    }
}

Status PopElement(Stack *stack, void **re) { // Use a double pointer to return the popped element
    if (stack == NULL) {
        printf("Failed\n");
        return S_no;
    } else {
        if (stack->pointer == -1) {
            printf("Stack is Empty\n");
            return S_empty;
        } else {
            *re = stack->size[stack->pointer]; // Use the double pointer to store the popped element
            stack->pointer--;
            return S_yes;
        }
    }
}
