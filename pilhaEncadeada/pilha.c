#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* criarPilha(unsigned int tam) {
  Pilha *p = (Pilha*) malloc(sizeof(Pilha));
  p->inicio = NULL;
  return p;
}

void destroiPilha(Pilha* p) {
  NoPilha *aux = p->inicio;
  while(p->inicio != NULL) {
    aux = p->inicio->prox;
    free(p->inicio);
    p->inicio = aux;
  }
  free(p);
}

void pushPilha(Pilha* p, int elem) {
  NoPilha *ptr = (NoPilha*) malloc(sizeof(NoPilha));
  ptr->elem = elem;
  ptr->prox = p->inicio;
  p->inicio = ptr;

}

int popPilha(Pilha* p) {

  if (pilhaVazia(p)) {
    printf("Pilha vazia!\n");
    exit(1);
  }

  //recupera o valor do elemento
  int elem = p->inicio->elem;
  //guarda o ponteiro para dar free
  NoPilha* aux = p->inicio;
  //atualiza o inicio da lista
  p->inicio = p->inicio->prox;
  free(aux);

  return elem;
}

int pilhaVazia(Pilha* p) {
  return p->inicio == NULL;
}

int verTopo(Pilha *p) {
  if (pilhaVazia(p)) {
    printf("Pilha vazia!\n");
    exit(1);
  }
  return p->inicio->elem;
}
