#ifndef PILHA_H
#define PILHA_H

typedef struct noPilha {
  int elem;
  struct noPilha* prox;
} NoPilha;

typedef struct pilha {
  NoPilha* inicio;
} Pilha;

Pilha* criarPilha();
void destroiPilha(Pilha* p);
void pushPilha(Pilha* p, int elem);
int popPilha(Pilha* p);
int pilhaVazia(Pilha* p);
int verTopo(Pilha *p);


#endif
