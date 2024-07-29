#include "arrayStack.h"

ArrayStack* createArrayStack() {
  ArrayStack* stack = (ArrayStack*)malloc(sizeof(ArrayStack));
  if (stack == NULL) {
    printf("create stack malloc failed\n");
    return NULL;
  }

  stack->top = -1;

  return stack;
}

void releaseArrayStack(ArrayStack* stack) {
  if (stack) {
    free(stack);
  }
}

int pushArrayStack(ArrayStack* stack, pTreeNode e) {
  if (stack->top + 1 == MAXSIZE) {
    printf("OverFlow\n");
    return -1;
  }

  stack->data[++stack->top] = e;

  return 0;
}

int popArrayStack(ArrayStack* stack, pTreeNode* e) {
  if (stack->top < 0) {
    printf("UnderFlow\n");
    return -1;
  }

  *e = stack->data[stack->top--];
  return 0;
}
