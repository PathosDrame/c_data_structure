#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct node {
  Element elem;
  struct node* next;
} Node;

typedef struct {
  Node* front;
  Node* rear;
  int cnt;
} LinkQueue;

LinkQueue* createLinkQueue();

void releaseLinkQueue(LinkQueue* que);

int pushLinkQueue(LinkQueue* que, Element e);

int popLinkQueue(LinkQueue* que, Element* e);
