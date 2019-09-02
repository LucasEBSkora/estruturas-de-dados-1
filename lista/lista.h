#ifndef LISTA_H
#define LISTA_H

typedef struct no {
  int elem;
  struct no *prox;
} Lista;

Lista* criarLista();
void destruirLista(Lista *l);
Lista* inserirElementoInicio(Lista* l, int elem);
void imprimirLista(Lista *l);
Lista* removerElemento(Lista* l, int elem);
int tamanhoLista(Lista* l);
Lista* procurarElemento(Lista* l, int elem);
Lista* separarLista(Lista* l, int elem);
#endif
