#include "../../filaEncadeada/fila.h"

#include <stdio.h>

int main () {
  int i, m, n;
  printf("Josephus - digite o passo da morte e numero de competidores: ");
  scanf("%d %d", &m, &n);
  Queue *q = create_queue();
  for (i = 1; i <= n; ++i) {
    enqueue(q, i);
  }
  i = 1;

  while (!queue_empty(q)) {
    int e = dequeue(q);

    if (queue_empty(q)) {
      printf(", sobrevivente: %d\n", e);
    } else if ((i % m) == 0) {
      printf("%d ", e);
    } else {
      enqueue(q, e);
    }
    ++i;
  }
  destroy_queue(q);
  return 0;
}
