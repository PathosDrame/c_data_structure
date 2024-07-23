#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct node {
  Element e;
  struct node *next;
} Node;

typedef struct {
  Node *top;
  int cnt;
} LinkStack;

LinkStack *createLinkStack();

void releaseLinkStack(LinkStack *stack);

int pushLinkStack(LinkStack *stack, Element e);

int popLinkStack(LinkStack *stack, Element *e);
