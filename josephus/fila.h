#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int start;
    int end;
    int size;
    int *array;
} Queue;

Queue* create_queue(int size);
void destroy_queue(Queue* q);
void enqueue(Queue* q, int elem);
int dequeue(Queue* q);
int queue_empty(Queue* q);
int queue_full(Queue* q);

#endif
