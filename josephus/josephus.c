#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main (int argc, char *argv[]) {
  
  if (argc != 3) {
    printf("Numero inadequado de parametros!an");
    return 1;
  }

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);
  

  if (m < 1 || n < 1) {
    printf("Erro! Parametros invalidos\n");
    return 1;
  }

  Queue *q = create_queue(n);


  //preenche a fila com os números de 1 a n
  int i;
  for (i = 1; i <= n; ++i) 
    enqueue(q, i);
  
  i = 0;
  while(!queue_empty(q)) {

    ++i;

    //se estiver na m-ésima "pessoa", a tira da lista permanentemente 
    if (i == m) {
      i = 0;
      printf(" %d", dequeue(q));
    }  else {
      //do contrário, coloca ela no final da lista
      enqueue(q, dequeue(q));
    }
  }

  printf("\n");
  
  destroy_queue(q);
  return 0;
}
