#include "../../fila/fila.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX 100
#define N 10

int main () {
  
  //o "sacrifício" é feito dentro da função, para que a fila tenha
  //o tamanho esperado pelo usuário
  Queue *par = create_queue(N);
  Queue *impar = create_queue(N);
  
  srand(time(NULL));

  int i;
  for(i = 0; i < N; ++i) {
    int num = rand() % MAX;
    if (num % 2 == 0) enqueue(par, num);
    else enqueue(impar, num);
  }

  printf("pares: ");
  print_queue(par);
  printf("impares: ");
  print_queue(impar);
  
  destroy_queue(par);
  destroy_queue(impar);
  return 0;
}