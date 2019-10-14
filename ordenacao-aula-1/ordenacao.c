#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocaProximo(int *vetor, int tam, int pos) {
  if (pos < tam -1) {
    int aux1 = vetor[pos];
    vetor[pos] = vetor[pos+1];
    vetor[pos + 1] = aux1;
  }
}

void Ordena1 (int *vetor, int tamanho) {
  int i;
  while (tamanho > 2) {
    for (i = 0; i < tamanho - 1; ++i) {
      if (vetor[i] > vetor[i+1]) trocaProximo(vetor, tamanho, i);
    }
    --tamanho;
  }
}

void troca2(int *vetor, int tam, int pos1, int pos2) {
  if (pos1 < tam && pos2 < tam) {
    int aux1 = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = aux1;
  }
}

void Ordena2 (int *vetor, int tamanho) {
  int i, j, posMenor;
  for (i = 0; i < tamanho; ++i) {

    posMenor = i;

    for (j = i; j < tamanho; ++j) {
      if (vetor[j] < vetor[posMenor])
        posMenor = j;
    }

    if (i != posMenor) troca2(vetor, tamanho, i, posMenor);
  }
}

void empurra(int *vetor, int tamanho, int pos) {
  if (pos < tamanho -1)
    vetor[pos+1] = vetor[pos];
}


void Ordena3 (int *vetor, int tamanho) {
  int jaOrdenado;
  int i;
  int novoValor;
  for(jaOrdenado = 0; jaOrdenado < tamanho - 1; ++jaOrdenado) {

    novoValor = vetor[jaOrdenado + 1];

    for (i = jaOrdenado; i >= 0; --i) {
      if (novoValor < vetor[i]) empurra(vetor, tamanho, i);
      else break;
    }

    vetor[i + 1] = novoValor;
  }
}

void Imprimir (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d, ", A[i]);
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


int main (int argc, char *argv[]) {

  if (argc != 2) {
    printf("usage: .\\ex <size of sets to test with>\n");
    return 0;
  }

  int tamanho = atoi(argv[1]);

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;


  int *v1 = (int *)malloc(tamanho * sizeof(int));
  int *v2 = (int *)malloc(tamanho * sizeof(int));
  int *v3 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
     v1[i] = rand() % (tamanho+1);
     v2[i] = rand() % (tamanho+1);
     v3[i] = rand() % (tamanho+1);
  }

  start = clock();
  //Imprimir(v1, tamanho);
  Ordena1 (v1, tamanho);
  //Imprimir(v1, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (ordenação 1): %f\n", elapsed_time);
  if (!Verifica_Ordenacao(v1, tamanho)) {
     printf("Erro: a ordenação 1 não está correta!\n");
  }

  start = clock();
  //Imprimir(v2, tamanho);
  Ordena2 (v2, tamanho);
  //Imprimir(v2, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (ordenação 2): %f\n", elapsed_time);
  if (!Verifica_Ordenacao(v2, tamanho)) {
     printf("Erro: a ordenação 2 não está correta!\n");
  }

  start = clock();
  //Imprimir(v3, tamanho);
  Ordena3 (v3, tamanho);
  //Imprimir(v3, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (ordenação 3): %f\n", elapsed_time);
  if (!Verifica_Ordenacao(v3, tamanho)) {
     printf("Erro: a ordenação 3 não está correta!\n");
  }

  free (v1);
  free (v2);
  free (v3);

  return 0;
}
