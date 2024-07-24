#include "linkQueue.h"

int main(int argc, char const* argv[]) {
  LinkQueue* que = createLinkQueue();
  for (int i = 0; i < 5; ++i) {
    pushLinkQueue(que, i + 1);
  }

  printf("node %d\n", que->cnt);

  Element e;
  for (int i = 0; i < 5; ++i) {
    popLinkQueue(que, &e);
    printf("%d\t", e);
  }
  printf("\n");

  popLinkQueue(que, &e);

  releaseLinkQueue(que);
  return 0;
}