#include "arrayQueue.h"

int main(int argc, char const* argv[]) {
  ArrayQueue* que = createArrayQueue();
  for (int i = 0; i < 4; ++i) {
    pushArrayQueue(que, i + 1);
  }

  pushArrayQueue(que, 5);

  Element e;
  for (int i = 0; i < 4; ++i) {
    popArrayQueue(que, &e);
    printf("%d\t", e);
  }

  printf("\n");

  popArrayQueue(que, &e);

  releaseArrayQueue(que);

  return 0;
}
