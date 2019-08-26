#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
  int *vetor;
  long unsigned int tamanho;
  long unsigned int topo;
} Pilha;

Pilha* criarPilha(unsigned int tam);
void destroiPilha(Pilha* p);
void pushPilha(Pilha* p, int elem);
int popPilha(Pilha* p);
int pilhaCheia(Pilha* p);
int pilhaVazia(Pilha* p);
int verTopo(Pilha *p);


#endif
