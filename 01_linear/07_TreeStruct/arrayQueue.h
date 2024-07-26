#ifndef _ARRAYQUEUE_
#define _ARRAYQUEUE_

#include "binaryTree.h"

#define MAXQUEUE 20

typedef struct {
  pTreeNode data[MAXQUEUE];
  int front;
  int rear;
} ArrayQueue;

ArrayQueue* createArrayQueue();

void releaseArrayQueue(ArrayQueue* que);

int pushArrayQueue(ArrayQueue* que, pTreeNode e);

int popArrayQueue(ArrayQueue* que, pTreeNode* e);
#endif