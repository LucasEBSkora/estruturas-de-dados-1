#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

Queue* create_queue(long unsigned int size) {
  Queue* q = (Queue*) malloc(sizeof(Queue));
  q->start = 0;
  q->end = 0;
  //deixa o espaço para o "sacrifício" dentro das funções,
  //para que a fila tenha o tamanho esperado pelo usuário
  q->size = size + 1;
  q->array = (int*) malloc((size + 1) * sizeof (int));
  return q;
}

void destroy_queue(Queue* q){
  free(q->array);
  free(q);
}

void enqueue(Queue* q, int elem) {
  if (queue_full(q)) {
    printf("Fila cheia!\n");
    exit(1);
  }
  q->array[q->end] = elem;
  q->end = circular_increment(q->end, q->size);
}

int dequeue(Queue* q) {
  if (queue_empty(q)) {
    printf("Fila vazia!\n");
    exit(1);
  }
  int elem = q->array[q->start];
  q->start = circular_increment(q->start, q->size);
  return elem;
}

int queue_empty(Queue* q) {
  return q->start == q->end;
}

int queue_full(Queue* q) {
  return q->start == circular_increment(q->end, q->size);
}

void print_queue(Queue* q) {

  long unsigned int i;

  for (i = q->start; i != q->end; i = circular_increment(i, q->size))
    printf("%d ", q->array[i]);

  printf("\n");
}

long unsigned int circular_increment(long unsigned int index, long unsigned int size) {
  return (index+1)%size;
}

long unsigned int get_queue_size(Queue *q) {
//-1 para que seja retornado o tamanho "efetivo" da lista
  return q->size - 1;
}

int peek_next(Queue *q) {
  if (queue_empty(q)) {
    printf("Fila vazia!\n");
    exit(1);
  }
  return q->array[q->start];
}
