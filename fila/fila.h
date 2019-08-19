#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    long unsigned int start;
    long unsigned int end;
    long unsigned int size;
    int *array;
} Queue;

Queue* create_queue(long unsigned int size);
void destroy_queue(Queue* q);
void enqueue(Queue* q, int elem);
int dequeue(Queue* q);
int queue_empty(Queue* q);
int queue_full(Queue* q);
void print_queue(Queue* q);
long unsigned int get_queue_size(Queue *q);
int peek_next(Queue *q);
long unsigned int circular_increment(long unsigned int index, long unsigned int size);

#endif
