#include "../../pilha/pilha.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void posfixa(char *str);
int eOperador(char c);
int main () {
  char* str = "(9+((0+1)*(2*3)))";
  printf("%s = ", str);
  posfixa(str);
  printf("%s\n", str);
  return 0;
}

void posfixa(char* str) {
  int tam = strlen(str);
  char* nstr = (char*) malloc(tam*sizeof(char));
  Pilha* p = criarPilha(tam);
  //iterador para a string original
  int i;
  //iterador para a string pós-fixa
  int j = 0;
  for(i = 0; i < tam; ++i) {
    if ('0' <= str[i] && str[i] <= '9') {
      nstr[j++] = str[i];
      if(eOperador(verTopo(p))) {
        nstr[j++] = popPilha(p);
      }
    } else if (str[i] == ')') {
      if(verTopo(p) != '(') printf("erro de formacao!\n");
      popPilha(p);
      if (eOperador(verTopo(p))) nstr[j++] = popPilha(p);
    } else if (eOperador(str[i]) || str[i] == '(') {
       pushPilha(p, str[i]);
    }

  }
  nstr[j] = '\0';

  strcpy(str, nstr);
  free(nstr);
}

int eOperador(char c) {
  return (c  == '+') || (c  == '-') || (c  == '*') || (c  == '/');
}
