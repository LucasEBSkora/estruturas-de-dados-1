#include "../../fila/fila.h"
#include <stdio.h>

Queue* concat(Queue* q1, Queue *q2);

int main() {
  
  //o "sacrifício" é feito dentro da função, para que a fila tenha
  //o tamanho esperado pelo usuário
  Queue *q1 = create_queue(4);
  Queue *q2 = create_queue(7);
  
  enqueue(q1, 1);
  enqueue(q1, 3);
  enqueue(q1, 5);
  enqueue(q1, 7);

  enqueue(q2, 2);
  enqueue(q2, 4);
  enqueue(q2, 5);
  enqueue(q2, 6);
  enqueue(q2, 8);
  enqueue(q2, 9);
  enqueue(q2, 10);

  printf("q1: ");
  print_queue(q1);
  printf("q2: ");
  print_queue(q2);
  
  Queue *q3 = concat(q1, q2);

  printf("q3: ");
  print_queue(q3);

  destroy_queue(q3);
  
  return 0;
}

Queue* concat(Queue* q1, Queue *q2) {

  //cria fila com o tamanho somado das duas filas passadas 
  //(lembrando que o "sacríficio" é feito dentro de create_queue())
  Queue *q = create_queue( get_queue_size(q1) + get_queue_size(q2));

  
  while (!queue_empty(q1) || !queue_empty(q2)) {

    //se uma das filas estiver vazia, termina de esvaziar a outra

    if (queue_empty(q1)) enqueue(q, dequeue(q2));
    else if (queue_empty(q2)) enqueue(q, dequeue(q1));

    //do contrário, verifica qual tem o menor elemento
    else if (peek_next(q1) <= peek_next(q2)) enqueue(q, dequeue(q1));
    else enqueue(q, dequeue(q2));

  }

  destroy_queue(q1);
  destroy_queue(q2);

  return q;
}