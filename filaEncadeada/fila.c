#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

Queue* create_queue() {
  Queue* q = (Queue*) malloc(sizeof(Queue));
  q->size = 0;
  q->start = NULL;
  return q;
}

void destroy_queue(Queue* q){
  QueueNode *aux;
  while (q->start != NULL) {
    aux = q->start->next;
    free(q->start);
    q->start = aux;
  }

  free(q);
}

void enqueue(Queue* q, int elem) {
  ++(q->size);

  QueueNode* ptr = (QueueNode*) malloc(sizeof(QueueNode));

  ptr->elem = elem;
  ptr->next = q->start;

  q->start = ptr;

}

int dequeue(Queue* q) {
  if (queue_empty(q)) {
    printf("Fila vazia!\n");
    exit(1);
  }

  --(q->size);

  QueueNode* el = q->start;
  QueueNode* aux = NULL;

  //encontra o último e penúltimo elementos da lista
  while (el->next != NULL) {
    aux = el;
    el = el->next;
  }

  int returnValue = el->elem;

  //se não há penultimo elemento, a fila só tem um elemento
  if (aux == NULL) q->start = NULL;
  else aux->next = NULL;

  free(el);

  return returnValue;
}

int queue_empty(Queue* q) {
  return q->start == NULL;
}

void print_queue(Queue* q) {

  QueueNode* ptr;

  for (ptr = q->start; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->elem);
  }

  printf("\n");
}

long unsigned int get_queue_size(Queue *q) {
//-1 para que seja retornado o tamanho "efetivo" da lista
  return q->size;
}

int peek_next(Queue *q) {
  if (queue_empty(q)) {
    printf("Fila vazia!\n");
    exit(1);
  }

  --(q->size);

  QueueNode* el = q->start;

  //encontra o último elementos da lista
  while (el->next != NULL) el = el->next;

  return el->elem;
}
