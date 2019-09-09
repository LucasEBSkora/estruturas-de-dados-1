#include "../../pilhaEncadeada/pilha.h"

#include <stdio.h>

int main () {
  int i = 0;
  char *expr = "( 9 + ((0 + 1) * (2*3)))";
  Pilha* p = criarPilha();
  while(expr[i] != '\0') {
    if ((expr[i] == '+') || (expr[i] == '*')) {
      pushPilha(p, expr[i]);
    } else if (expr[i] == ')') {
      printf("%c", popPilha(p));
    } else if ((expr[i] >= '0') && (expr[i] <= '9')) {
      printf("%c", expr[i]);
    }
    i++;
  }
  printf("\n");
  destroiPilha(p);
  return 0;
}
