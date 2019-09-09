#ifndef FILA_H
#define FILA_H

typedef struct queueNode {
  int elem;
  struct queueNode* next;
} QueueNode;

typedef struct queue {
    long unsigned int size;
    QueueNode *start;

} Queue;


Queue* create_queue();
void destroy_queue(Queue* q);
void enqueue(Queue* q, int elem);
int dequeue(Queue* q);
int queue_empty(Queue* q);
void print_queue(Queue* q);
long unsigned int get_queue_size(Queue *q);
int peek_next(Queue *q);

#endif
