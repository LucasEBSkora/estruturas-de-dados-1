#include "fila.h"

Queue* create_queue(int size) {
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
  q->end = (q->end + 1)%q->size;
}

int dequeue(Queue* q) {
  if (queue_empty(q)) {
    printf("Fila vazia!\n");
    exit(1);
  }
  int elem = q->array[q->start];
  q->start = (q->start + 1)%q->size;
  return elem;
}

int queue_empty(Queue* q) {
  return q->start == q->end;
}

int queue_full(Queue* q) {
  return q->start == ((q->end + 1)%q->size);
}

void print_queue(Queue* q) {
  int i;
  for (i = q->start; i != q->end; i = (i + 1)%q->size) {
    printf("%i ", q->array[i]);
  }
  printf("\n");
}