#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
Pilha* criarPilha(unsigned int tam) {
  Pilha *p = (Pilha*) malloc(sizeof(Pilha));
  p->tamanho = tam;
  p->vetor = (int*) malloc(sizeof(int) * tam);
  p->topo = 0;
  return p;
}

void destroiPilha(Pilha* p) {
  free(p->vetor);
  free(p);
}

void pushPilha(Pilha* p, int elem) {
  if (pilhaCheia(p)) {
    printf("Pilha cheia!\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  ++(p->topo);
}

int popPilha(Pilha* p) {
  if (pilhaVazia(p)) {
    printf("Pilha vazia!\n");
    exit(1);
  }
  --(p->topo);
  return p->vetor[p->topo];
}

int pilhaCheia(Pilha* p) {
  return p->topo == p->tamanho;
}

int pilhaVazia(Pilha* p) {
  return p->topo == 0;
}

int verTopo(Pilha *p) {
  return p->vetor[p->topo - 1];
}
