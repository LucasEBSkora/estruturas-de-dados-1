#include "../pilha/pilha.h"
#include <stdio.h>

int main () {
  Pilha* p = criarPilha(5);
  int i;
  for (i = 0; !pilhaCheia(p); ++i) pushPilha(p, i);

  while(!pilhaVazia(p)) printf("%d\n", popPilha(p));

  destroiPilha(p);

  return 0;
}
