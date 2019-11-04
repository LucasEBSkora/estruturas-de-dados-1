#include <stdio.h>
#include <stdlib.h>

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
  int v[10] = {661, 272, 500, 737, 874, 20, 69, 609, 924, 772};

  //ordenar o conjunto
  QuickSort(v, 0, 9);


  //e daí simplesmente verificar a distância entre elementos subsequentes
  int el1 = v[0], el2 = v[1], dif = el2 - el1;
  int i;
  for (i = 1; i < 9; ++i) {
    if (v[i+1] - v[i] < dif) {
      el1 = v[i];
      el2 = v[i+1];
      dif = el2-el1;
    }
  }

  printf("os elementos com a menor distancia são %d e %d\n", el1, el2);


  return 0;
}
