//
// Created by xcite on 10/10/2023.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Structure for the Queue.
 */
typedef struct {
    void **pointer; ///< Array to hold queue elements (void pointers).
    int max_size;   ///< Maximum size of the queue.
    int counter;    ///< Number of elements in the queue.
    int rear;       ///< Index of the rear element.
    int front;      ///< Index of the front element.
} Queue;

/**
 * @brief Enumeration for queue operation status.
 */
typedef enum {
    Q_SUCCESS, ///< Operation was successful.
    Q_EMPTY,   ///< Queue is empty.
    Q_FULL,    ///< Queue is full.
    Q_ERROR    ///< General error.
} Status;

/**
 * @brief Create a new queue with the specified size.
 *
 * @param size The maximum size of the queue.
 * @return A pointer to the newly created queue.
 */
Queue *CreateQueue(int size);

/**
 * @brief Enqueue an item into the queue.
 *
 * @param my_q A pointer to the queue.
 * @param item A pointer to the item to be enqueued.
 * @return Status indicating success or failure.
 */
Status Enque(Queue *my_q, void *item);

/**
 * @brief Dequeue an item from the queue.
 *
 * @param my_q A pointer to the queue.
 * @param s A pointer to a Status variable to store the status of the operation.
 * @return A pointer to the dequeued item.
 */
void *Deque(Queue *my_q, Status *s);

/**
 * @brief Get the front item without dequeuing.
 *
 * @param my_q A pointer to the queue.
 * @param s The status of the operation.
 * @return A pointer to the front item.
 */
void *Front(Queue *my_q, Status s);

/**
 * @brief Check if the queue is empty.
 *
 * @param my_q A pointer to the queue.
 * @return true if the queue is empty, false otherwise.
 */
bool IsEmpty(Queue *my_q);

/**
 * @brief Check if the queue is full.
 *
 * @param my_q A pointer to the queue.
 * @return true if the queue is full, false otherwise.
 */
bool IsFull(Queue *my_q);

/**
 * @brief Get the number of elements in the queue.
 *
 * @param my_q A pointer to the queue.
 * @return The number of elements in the queue.
 */
int Size(Queue *my_q);

/**
 * @brief Clear the queue (reset to the initial state).
 *
 * @param my_q A pointer to the queue.
 */
void Clear(Queue *my_q);

/**
 * @brief Destroy the queue and free memory.
 *
 * @param my_q A pointer to the queue to be destroyed.
 * @return NULL after freeing the memory.
 */
Queue *Destroy(Queue *my_q);

/**
 * @brief Print the queue.
 *
 * @param my_q A pointer to the queue.
 */
void print_Q(Queue *my_q);

#endif //QUEUE_QUEUE_H
