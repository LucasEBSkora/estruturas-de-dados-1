#include "../../pilha/pilha.h"
#include <string.h>
#include <stdio.h>

int bemFormado(const char *str);

int main () {
  const char* strings[4] = {
    "(()[()])", "([)]",
    "()[]", "([]"
  };
  int i;
  for(i = 0; i < 4; ++i) {
    printf("%s ", strings[i]);
    if (bemFormado(strings[i])) printf("bem formado!\n");
    else printf("mal formado!\n");
  }

  return 0;
}

int bemFormado(const char* str) {
  unsigned int tam = strlen(str);
  Pilha *p = criarPilha(tam);

  unsigned int i;
  for (i = 0; i < tam; ++i) {
    //se chega a um caractere que abre alguma coisa, o adiciona na fila
     if (str[i] == '(' || str[i] == '[' || str[i] == '{') pushPilha(p, str[i]);
     //se chega em um caractere que fecha alguma coisa
     else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
       //verifica se ele fecha a ultima coisa aberta, que é a última adicionada na fila
       char c = popPilha(p);
       if ((c == '(' && str[i] == ')') ||
          (c == '[' && str[i] == ']')  ||
          (c == '{' && str[i] == '}')) continue;
          else {
            destroiPilha(p);
            return 0;
          }
     } //se algum caractere alem de (), [], {} ou espaços forem utilizados, marca a string como mal-formada
     else if (str[i] != ' ') {
       destroiPilha(p);
       return 0;
     }
  }
  //se a pilha terminar sem estar vazia, existem coisas que não foram fechadas, e, portanto, a string está mal-formada
  if (!pilhaVazia(p)) {
    destroiPilha(p);
    return 0;
  } else {
    destroiPilha(p);
    return 1;
  }

}
