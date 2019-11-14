#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Definição de uma imagem.*/
typedef struct _imagem {
  int nlinhas;   /*Número de linhas da imagem.*/
  int ncolunas;   /*Número de colunas da imagem.*/
  int **mat;  /*Matriz para armazenar os pixels.*/
} Imagem;

/*Alocando a estrutura da imagem.*/
Imagem* aloca_imagem (int nlinhas, int ncolunas) {
  int i;
  Imagem *img = (Imagem *)malloc(sizeof(Imagem));
  img->nlinhas = nlinhas;
  img->ncolunas = ncolunas;
  img->mat = (int **)malloc(ncolunas * sizeof(int *));
  for (i = 0; i < ncolunas; i++) {
    img->mat[i] = (int *)malloc(nlinhas * sizeof(int));
  }
  return img;
}

/*Liberando estruturas da imagem.*/
void desaloca_imagem (Imagem *img) {
  int i;
  for (i = 0; i < img->ncolunas; i++) {
    free(img->mat[i]);
  }
  free(img->mat);
  free(img);
}

void criarVetor(int **m, int i, int j, int tamanho_da_janela, int* v) {

  int k,l;

  for (k = -ceil(tamanho_da_janela/2); k <= tamanho_da_janela/2; ++k) {
    for(l = -ceil(tamanho_da_janela/2); l <= tamanho_da_janela/2; ++l) {
      *(v++) = m[i  + k ][j + l];
    }
  }
  

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

int mediana(int* v, int tamanho) {
  return QuickFind(v, 0, tamanho - 1, tamanho/2);
}

Imagem* Processamento (Imagem *img, int tamanho_da_janela) {
  Imagem* nova = aloca_imagem(img->nlinhas, img->ncolunas);

  int *v = (int*) malloc( sizeof(int) * tamanho_da_janela * tamanho_da_janela);

  int i, j;
  for (i = 0; i < img->nlinhas; ++i)
    for (j = 0; j < img->ncolunas; ++j) {
      int k, l;

      k = (i < floor(tamanho_da_janela/2)) ? floor(tamanho_da_janela/2) : i;
      l = (j < floor(tamanho_da_janela/2)) ? floor(tamanho_da_janela/2) : j;

      if (k > img->nlinhas - 1 - floor(tamanho_da_janela/2)) k = img->nlinhas - 1 - floor(tamanho_da_janela/2);
      if (l > img->ncolunas - 1 - floor(tamanho_da_janela/2)) l = img->ncolunas -1 - floor(tamanho_da_janela/2);

      criarVetor(img->mat, k, l, tamanho_da_janela, v);

      nova->mat[i][j] = mediana(v, tamanho_da_janela * tamanho_da_janela);
    }

  free(v);
  return nova;

}

int main () {
  /**/
  FILE *fin  = fopen("imagens/lena.pgm", "r");
  FILE *fout = fopen("saida.pgm", "w");
  int tamanho_da_janela = 21; /*Teste com tamanhos: 3, 5, 7, 9, ... (sempre ímpar)*/

  /*Lendo a imagem:*/
  int nlinhas, ncolunas, nlevels;
  char *type = (char *)malloc(sizeof(char));
  fscanf(fin, "%s", type);
  fscanf(fin, "%d %d %d", &ncolunas, &nlinhas, &nlevels);
  Imagem *imagem_entrada = aloca_imagem (nlinhas, ncolunas);
  int i, j;
  for (j = 0; j < imagem_entrada->nlinhas; j++) {
    for (i = 0; i < imagem_entrada->ncolunas; i++) {
      fscanf(fin, "%d", &(imagem_entrada->mat[i][j]));
    }
  }
  fclose(fin);

  /*Processando a imagem para remocao de ruido:*/
  Imagem *imagem_saida = Processamento (imagem_entrada, tamanho_da_janela);

  /*Gravando a imagem com o resultado do processamento:*/
  fprintf(fout, "%s\n%d %d\n%d\n", type, imagem_saida->ncolunas, imagem_saida->nlinhas, nlevels);
  for (j = 0; j < imagem_saida->nlinhas; j++) {
    for (i = 0; i < imagem_saida->ncolunas; i++) {
      fprintf(fout, "%d ", imagem_saida->mat[i][j]);
      if ( (j != 0) && ((j % 12) == 0) ) {
        fprintf(fout, "\n");
      }
    }
  }
  fclose(fout);
  desaloca_imagem (imagem_entrada);
  desaloca_imagem (imagem_saida);
  return 0;
}
