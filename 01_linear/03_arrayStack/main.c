#include "arrayStack.h"

int main(int argc, char const* argv[]) {
  ArrayStack* stack = createArrayStack();

  for (int i = 0; i < 5; ++i) {
    pushArrayStack(stack, i + 100);
  }

  // for (int i = 0; i < 5; ++i) {
  //   printf("%d\t", stack->data[i]);
  // }
  // printf("\n");

  // OverFlow
  pushArrayStack(stack, 500);

  Element e = 0;
  for (int i = 0; i < 5; ++i) {
    popArrayStack(stack, &e);
    printf("%d\t", e);
  }
  printf("\n");

  // UnderFlow
  popArrayStack(stack, &e);

  releaseArrayStack(stack);

  return 0;
}
