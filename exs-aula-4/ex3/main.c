#include "../../lista/lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

  int v;

  Lista *lista1 = criarLista();

  srand(time(NULL));

  do {
    v = rand() % 14;
    lista1 = inserirElementoInicio(lista1, v);
  } while (v != 7);

  printf("Lista 1 antes da separacao:\n");
  imprimirLista(lista1);

  printf("Digite o elemento de separacao:\n");
  scanf("%d", &v);

  Lista* lista2 = separarLista(lista1, v);

  printf("Lista 1 depois da separacao:\n");
  imprimirLista(lista1);

  printf("Lista 2 depois da separacao:\n");
  imprimirLista(lista2);

  destruirLista(lista1);
  destruirLista(lista2);

  return 0;
}
