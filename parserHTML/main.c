#include "../pilhaEncadeada/pilha.h"

#include <stdio.h>
#include <stdlib.h>

enum {
  body, h1, center, p, ol, li
};


int main (int argc, char *argv[]) {

  if (argc != 2) {
    printf("Numero inadequado de parametros!an");
    return 1;
  }

  char* caminho = argv[1];

  FILE *arquivo = fopen(caminho, "r");
  if (arquivo) {
    Pilha* pilha = criarPilha();
    char linha[128];
    while (fgets(linha, sizeof(linha), arquivo)) {

      //printf("%s", linha);
      int i;

      for (i = 0; linha[i] != '\0'; ++i) {
        //se encontrar o inicio de uma tag
        if(linha[i] == '<') {
          ++i;
          char tag[32];
          int j = 0;
          int tagValida = 0;

          while(linha[i] != '\0') {
            //
            if (linha[i] == '>') {
              tagValida = 1;
              break;
            } else {
              tag[j++] = linha[i];
            }

          }
          if (!tagValida) {
            printf("html invalido!\n");
            exit(1);
          } else tag[j] = '\0';
          printf("%s\n", tag);
        }
      }
    }

    destroiPilha(pilha);
    fclose(arquivo);
  } else {
    printf("erro! Arquivo não encontrado.");
  }

  return 0;

}
