#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, unsigned long int tamanho) {
  unsigned long int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}

void Imprimir (int *A, unsigned long int tamanho) {
  unsigned long int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", A[i]);
  }
  printf ("\n");
}

void trocar(int *v, int i, int j) {
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

int particionar(int *v, int l, int r) {
  int vPivo = v[r];
  int i = l;
  int j;
  for (j = l; j < r; ++j) {
    if (v[j] <= vPivo)
      trocar(v, i++, j);
  }
  trocar(v, i, r);

  return i;

}

void QuickSort(int* v, int l, int r) {
  if (l < r) {
      int q = particionar(v, l, r);
      QuickSort(v, l, q - 1);
      QuickSort(v, q + 1, r);
  }
}


/*Função principal.*/
int main (int argc, char *argv[]) {
   if (argc != 3) {
     printf("usage: ./ex n t\n\tt = 0 -> random\n\tt = 1 -> increasingn\tt = 2 -> decreasing\n");
     return 1;
   }

   unsigned long int tamanho = atoi(argv[1]);
   int t = atoi(argv[2]);
   if (t < 0 || t > 2) return 1;

   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   unsigned long int i;
   int *v = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      if (t == 0) v[i] = rand() % (tamanho+1);
      else if (t == 1) v[i] = i;
      else if (t == 2) v[i] = tamanho - i;
   }
   //Imprimir (v, tamanho);
   start = clock();
   QuickSort (v, 0, tamanho-1);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
   if (!Verifica_Ordenacao(v, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   //Imprimir (v, tamanho);
   free (v);
   return 0;
}
