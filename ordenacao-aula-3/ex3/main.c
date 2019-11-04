#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Troca dois elementos {i,j} de posição.*/
void Swap (char **A, int i, int j) {
  char *aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (char **A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (strcmp (A[i],A[i+1]) > 1) {
       return 0;
    }
  }
  return 1;
}

int particionar(char** v, int l, int r) {

  int al = rand() % (r-l + 1) + l;

  Swap(v, al, r);
  char* vPivo = v[r];
  int i = l;
  int j;
  for (j = l; j < r; ++j) {
    if (strcmp(v[j], vPivo) <= 0)
      Swap(v, i++, j);
  }
  Swap(v, i, r);

  return i;

}

/*Quick-Sort.*/
void QuickSort (char **A, int l, int r) {
  if (l < r) {
      int q = particionar(A, l, r);
      QuickSort(A, l, q - 1);
      QuickSort(A, q + 1, r);
  }
}

/*Função para contar o número de linhas de um arquivo.*/
unsigned long int conta_linhas (FILE *arq) {
  unsigned long int linhas = 0;
  if (arq == NULL) {
    return linhas;
  }
  while (!feof(arq)) {
    char c;
    fscanf(arq, "%c", &c);
    if (c == '\n') {
      linhas++;
    }
  }
  rewind(arq);
  return (linhas-1);
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   srand(time(NULL));

   /*Abrindo o arquivo:*/
   FILE *arq = fopen("palavras.txt", "r"); //fopen(argv[1],"r");

   /*Contando o número de linhas do arquivo:*/
   unsigned long int linhas = conta_linhas(arq);
   printf("O número de linhas do arquivo é: %lu\n", linhas);

   /*Alocando memória para armazenar as palavras:*/
   char **palavras = (char **)malloc(linhas * sizeof(char *));
   unsigned int i;
   for (i = 0; i < linhas; i++) {
      palavras[i] = (char *)malloc(256 * sizeof(char));
   }

   /*Lendo as palavras do arquivos:*/
   i = 0;
   while (!feof(arq)) {
      fscanf(arq, "%s", palavras[i]);
      i++;
   }

   /*Ordenando as palavras:*/
   clock_t start = clock();
   QuickSort (palavras, 0, linhas-1);
   clock_t end = clock();
   double elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);

   /*Imprimindo as palavras:*/
   for (i = 0; i < linhas; i++) {
      printf("%s\n", palavras[i]);
   }

   /*Verificando se a ordenação está correta:*/
   if (!Verifica_Ordenacao(palavras, linhas)) {
      printf("Erro: a ordenação não está correta!\n");
   }

   /*Liberando a memória:*/
   for (i = 0; i < linhas; i++) {
      free(palavras[i]);
   }
   free(palavras);
   fclose(arq);
   return 0;
}
