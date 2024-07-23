#include "linkStack.h"

int main(int argc, char const* argv[]) {
  LinkStack* stack = createLinkStack();
  for (int i = 0; i < 5; ++i) {
    pushLinkStack(stack, i + 100);
  }

  printf("cnt: %d\n", stack->cnt);

  Element e;
  for (int i = 0; i < 5; ++i) {
    popLinkStack(stack, &e);
    printf("%d\t", e);
  }
  printf("\n");

  popLinkStack(stack, &e);

  releaseLinkStack(stack);

  return 0;
}
