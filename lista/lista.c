#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
Lista* criarLista() {
  return NULL;
}

void destruirLista(Lista *l) {
  Lista* aux;
  while (l != NULL ) {
    aux = l->prox;
    free(l);
    l = aux;
  }
}

Lista* inserirElementoInicio(Lista* l, int elem) {
  Lista* nl = (Lista*) malloc(sizeof(Lista));
  nl->elem = elem;
  nl->prox = l;
  return nl;
}

void imprimirLista(Lista *l) {
  for(;l != NULL; l = l->prox) printf("%d, ", l->elem);
  printf("\n");
}

Lista* removerElemento(Lista* l, int elem) {
  Lista *aux = l;
  Lista *ant = NULL;
  // procura o elemento (e seu predecessor na l)
  while (aux != NULL && aux->elem != elem) {
    ant = aux;
    aux = aux->prox;
  }
  // se encontrar o elemento, o remove
  if (aux != NULL) {
    // se o elemento for o primeiro da lista,
    // o remove e faz o inicio da lista apontar para o próximo
    if (aux == l) {
      l = aux->prox;
      free(aux);
    } else {
      // se o elemento estiver no meio da lista, faz o seu antecessor apontar
      // para o próximo e destroi o elemento (sem mover o início)
      if (ant != NULL) ant->prox = aux->prox;
      free(aux);
    }
  }
  return l;
}

int tamanhoLista(Lista* l) {
  int tam = 0;
  for (;l != NULL; l = l->prox) ++tam;
  return tam;
}

Lista* procurarElemento(Lista* l, int elem) {
  for (; l != NULL; l = l->prox) {
    if (l->elem == elem) return l;
  }
  return NULL;
}

Lista* separarLista(Lista* l, int elem) {

  // procura o elemento desejado na lista
  Lista* elementoSeparar = procurarElemento(l, elem);
  Lista* l2 = NULL;
  // se encontra o elemento, salva o próximo como início da lista 2
  // e faz com que o elemento seja o fim da lista 1.
  if (elementoSeparar != NULL) {
    l2 = elementoSeparar->prox;
    elementoSeparar->prox = NULL;
  }
  return l2;
}
