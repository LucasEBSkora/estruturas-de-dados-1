#include "../../lista/lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Lista* cria_circular(Lista *lista);

int main () {
  int v;
  Lista *lista = criarLista();
  srand(time(NULL));
  do {
    v = rand() % 30;
    lista = inserirElementoInicio (lista, v);
  } while (v != 12);

  cria_circular(lista);

  imprimirLista(lista);

  destruirLista(lista);
  return 0;
}

Lista* cria_circular(Lista *lista) {
  if (lista == NULL) return NULL;
  else {
    Lista* aux = lista;
    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = lista;
    return lista;
  }
}
