#include "../../lista/lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

  int v;
  Lista *lista = criarLista();

  srand(time(NULL));
  do {
    v = rand() % 10;
    lista = inserirElementoInicio (lista, v);
  } while (v != 9);

  imprimirLista(lista);

  int elem =  rand() % 10;
  Lista* nl = procurarElemento(lista, elem);

  if (nl == NULL) printf("o elemento %d nao existe na lista!\n", elem);
  else printf("o endereco de %d e : %p->%d\n", elem, (void *) nl, nl->elem);

  destruirLista(lista);
  return 0;
}
