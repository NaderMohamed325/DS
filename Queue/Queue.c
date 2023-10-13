//
// Created by xcite on 10/10/2023.
//

#include "Queue.h"



/**
 * @brief Create a new queue with the specified size.
 *
 * @param size The maximum size of the queue.
 * @return A pointer to the newly created queue.
 */
Queue *CreateQueue(int size) {
    Queue *my_q = NULL;
    my_q = (Queue *) malloc(sizeof(Queue));
    if (my_q == NULL) {
        printf("Failed to Create Queue\n"); // Error message for malloc failure
    } else {
        my_q->pointer = (void **) malloc(sizeof(void *) * size); // Allocate memory for the queue
        if (my_q->pointer != NULL) {
            my_q->counter = 0;
            my_q->front = -1;
            my_q->rear = -1;
            my_q->max_size = size;
        } else {
            printf("Can't Create Queue\n"); // Error message for malloc failure
        }
    }
    return my_q;
}

/**
 * @brief Enqueue an item into the queue.
 *
 * @param my_q A pointer to the queue.
 * @param item A pointer to the item to be enqueued.
 * @return Status indicating success or failure.
 */
Status Enque(Queue *my_q, void *item) {
    if (my_q == NULL || item == NULL) {
        return Q_ERROR; // Error if the queue or item is NULL
    } else {
        if (my_q->counter == my_q->max_size) {
            printf("The Queue is Full\n"); // Error message for a full queue
            return Q_FULL;
        } else {
            my_q->rear = (my_q->rear + 1) % my_q->max_size; // Circular queue logic for rear
            my_q->pointer[my_q->rear] = item;
            my_q->counter++;
            printf("Enqueue %p\n", item); // Print the address of the enqueued item
            return Q_SUCCESS;
        }
    }
}

/**
 * @brief Dequeue an item from the queue.
 *
 * @param my_q A pointer to the queue.
 * @param s A pointer to a Status variable to store the status of the operation.
 * @return A pointer to the dequeued item.
 */
void *Deque(Queue *my_q, Status *s) {
    if (my_q == NULL || s == NULL) {
        if (s != NULL) {
            *s = Q_ERROR;
        }
        printf("Can't Dequeue\n"); // Error message for invalid parameters
        return NULL;
    } else {
        if (my_q->counter == 0) {
            if (s != NULL) {
                *s = Q_EMPTY;
            }
            printf("Queue is Empty\n"); // Error message for an empty queue
            return NULL;
        } else {
            my_q->front = (my_q->front + 1) % my_q->max_size; // Circular queue logic for front
            my_q->counter--;
            if (s != NULL) {
                *s = Q_SUCCESS;
            }
            return my_q->pointer[my_q->front];
        }
    }
}

/**
 * @brief Get the front item without dequeuing.
 *
 * @param my_q A pointer to the queue.
 * @param s The status of the operation.
 * @return A pointer to the front item.
 */
void *Front(Queue *my_q, Status s) {
    if (my_q->counter == 0) {
        s = Q_EMPTY;
        printf("Queue is Empty\n"); // Error message for an empty queue
        return NULL;
    } else {
        s = Q_SUCCESS;
        return my_q->pointer[my_q->front];
    }
}

/**
 * @brief Check if the queue is empty.
 *
 * @param my_q A pointer to the queue.
 * @return true if the queue is empty, false otherwise.
 */
bool IsEmpty(Queue *my_q) {
    if (my_q->counter == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Check if the queue is full.
 *
 * @param my_q A pointer to the queue.
 * @return true if the queue is full, false otherwise.
 */
bool IsFull(Queue *my_q) {
    if (my_q->counter == my_q->max_size) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Get the number of elements in the queue.
 *
 * @param my_q A pointer to the queue.
 * @return The number of elements in the queue.
 */
int Size(Queue *my_q) {
    return my_q->counter;
}

/**
 * @brief Clear the queue (reset to initial state).
 *
 * @param my_q A pointer to the queue.
 */
void Clear(Queue *my_q) {
    my_q->counter = 0;
    my_q->front = -1;
    my_q->rear = -1;
}

/**
 * @brief Destroy the queue and free memory.
 *
 * @param my_q A pointer to the queue to be destroyed.
 * @return NULL after freeing the memory.
 */
Queue *Destroy(Queue *my_q) {
    free(my_q->pointer);
    free(my_q);
    return NULL;
}

/**
 * @brief Print the queue.
 *
 * @param my_q A pointer to the queue.
 */
void print_Q(Queue *my_q) {
    int i = 0;
    if (my_q->counter == 0) {
        printf("Queue is Empty\n");
    } else {
        printf("[");
        for (i = 0; i < my_q->counter; i++) {
            printf(" %p ", my_q->pointer[i]); // Print the address of queue elements
        }
        printf("]\n");
    }
}
