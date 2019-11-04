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

  int al = rand() % (r-l + 1) + l;

  trocar(v, al, r);
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

int QuickFind(int* v, int l, int r, int i) {
  if (l <= r) {
      int q = particionar(v, l, r);
      if (q == i) return v[q];
      else if (i < q) return QuickFind(v, l, q - 1, i);
      else return QuickFind(v, q + 1, r, i);
  } else {
    printf("deu ruim");
    exit(1);
  }
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
   if (argc != 4) {
     printf("usage: ./ex n i p\n\tn -> number of elements\n\ti -> position to find\n\tp -> print array\n");
     return 1;
   }

   unsigned long int tamanho = atoi(argv[1]);
   int i = atoi(argv[2]);
   int p = atoi(argv[3]);
   if (i < 0 || i > tamanho) return 1;

   srand(time(NULL));
   unsigned long int j;
   int *v = (int *)malloc(tamanho * sizeof(int));
   for (j = 0; j < tamanho; j++) {
      v[j] = rand() % (tamanho+1);

   }

   if (p) Imprimir (v, tamanho);

   printf("o %d-esimo elemento ordenado e %d\n", i, QuickFind (v, 0, tamanho-1, i));

   QuickSort(v, 0, tamanho - 1);

   if (p) Imprimir(v, tamanho);

   printf("o valor correto e %d\n", v[i]);

   free (v);
   return 0;
}
