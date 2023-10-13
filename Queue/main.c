#include <stdio.h>
#include "Queue.h"
int main() {
    Queue *my_q = NULL;
    my_q = CreateQueue(5);
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    Enque(my_q, &a);
    Enque(my_q, &b);
    Enque(my_q, &c);
    Enque(my_q, &d);
    Status s;
    int *item = Deque(my_q, &s);
    printf("Dequeue %p\n", item);
    item = Deque(my_q, &s);
    printf("Dequeue %p\n", item);
    item = Deque(my_q, &s);
    printf("Dequeue %p\n", item);
    item = Deque(my_q, &s);
    printf("Dequeue %p\n", item);
    item = Deque(my_q, &s);
    printf("Dequeue %p\n", item);
    return 0;



}
