#include "../../lista/lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
  int v;
  Lista *lista = criarLista();
  srand(time(NULL));
  do {
    v = rand() % 30;
    lista = inserirElementoInicio (lista, v);
  } while (v != 12);
  imprimirLista(lista);
  printf("O numero de nos e: %d\n", tamanhoLista(lista));
  destruirLista(lista);
  return 0;
}
