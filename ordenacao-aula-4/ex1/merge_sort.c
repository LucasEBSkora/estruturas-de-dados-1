#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*Troca dois elementos {i,j} de posição.*/
void Swap (int *A, int i, int j) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

/*Imprime o vetor:*/
void Imprimir (int *A, int tamanho) {
  int i;
  printf("Vetor:\n");
  for (i = 0; i < tamanho; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

/*Imprime o vetor:*/
void ImprimirPedaco (int *A, int esq, int dir) {
  int i;
  printf("Vetor:\n");
  for (i = esq; i <= dir; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
   int i;
   for (i = 0; i < tamanho-1; i++) {
      if (A[i] > A[i+1]) {
         return 0;
      }
   }
   return 1;
}

void Intercalar (int V[], int esq, int meio, int dir, int Vaux[]) {
  int i, j, k;

  for (i = esq; i <= dir; ++i) Vaux[i] = V[i];

  for (i = esq, j = meio + 1 , k = esq; i <= meio && j <= dir;)
    V[k++] = Vaux[(Vaux[i] <= Vaux[j]) ? i++ : j++];

  while (i <= meio)
    V[k++] = Vaux[i++];

  while (j <= dir)
    V[k++] = Vaux[j++];

}

void MergeSort (int V[], int esq, int dir, int Vaux[]) {

   if (esq < dir) {
     int p = floor((esq + dir)/2);
     MergeSort(V, esq, p, Vaux);
     MergeSort(V, p + 1, dir, Vaux);
     Intercalar(V, esq, p, dir, Vaux);
   }
}

/*Função principal.*/
int main (int argc, char *argv[]) {

  if (argc != 3) {
    printf("usage: ./ex n i\n\tn -> number of elements\n\tp -> print array\n");
    return 1;
  }

   int i, tamanho = atoi(argv[1]);
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int *v = (int *)malloc(tamanho * sizeof(int));
   int *vaux = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      v[i] = rand() % (tamanho+1); /*aleatório*/
      //v[i] = i; /*crescente*/
      //v[i] = tamanho - i; /*decrescente*/
   }
   if (atoi(argv[2])) Imprimir (v, tamanho);
   start = clock();
   MergeSort (v, 0, tamanho-1, vaux);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Merge-Sort): %.2f\n", elapsed_time);
   if (!Verifica_Ordenacao(v, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   if (atoi(argv[2])) Imprimir (v, tamanho);
   free (v);
   free (vaux);
   return 0;
}
