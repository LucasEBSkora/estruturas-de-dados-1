#include "../../fila/fila.h"

int main () {
  
  //o "sacrifício" é feito dentro da função, para que a fila tenha
  //o tamanho esperado pelo usuário
  Queue *q = create_queue (6);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 1);
  dequeue(q);
  dequeue(q);
  enqueue(q, 0);
  enqueue(q, 4);
  dequeue(q);
  dequeue(q);
  enqueue(q, 0);
  enqueue(q, 2);
  enqueue(q, 6);
  enqueue(q, 8);
  print_queue(q);
  destroy_queue(q);
  return 0;
}