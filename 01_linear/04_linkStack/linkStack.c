#include "linkStack.h"

LinkStack* createLinkStack() {
  LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));

  if (stack == NULL) {
    printf("create link stack malloc failed\n");
    return NULL;
  }

  stack->top = NULL;
  stack->cnt = 0;

  return stack;
}

void releaseLinkStack(LinkStack* stack) {
  if (stack) {
    int cnt = 0;
    while (stack->top) {
      Node* tmp = stack->top;
      stack->top = tmp->next;
      free(tmp);
      --stack->cnt;
    }
    printf("stack count %d\n", stack->cnt);
    free(stack);
  }
}

int pushLinkStack(LinkStack* stack, Element e) {
  Node* node = (Node*)malloc(sizeof(Node));

  if (node == NULL) {
    printf("creat node mallo failed\n");
    return -1;
  }

  node->e = e;

  node->next = stack->top;
  stack->top = node;

  ++stack->cnt;

  return 0;
}

int popLinkStack(LinkStack* stack, Element* e) {
  if (stack->top == NULL) {
    printf("pop failed\n");
    return -1;
  }

  *e = stack->top->e;
  Node* node = stack->top;
  stack->top = node->next;

  free(node);
  --stack->cnt;

  return 0;
}
