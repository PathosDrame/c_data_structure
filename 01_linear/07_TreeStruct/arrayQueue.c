#include "arrayQueue.h"

ArrayQueue* createArrayQueue() {
  ArrayQueue* que = (ArrayQueue*)malloc(sizeof(ArrayQueue));
  if (que == NULL) {
    printf("create array queue malloc failed\n");
    return NULL;
  }

  que->front = que->rear = 0;

  return que;
}

void releaseArrayQueue(ArrayQueue* que) {
  if (que) {
    free(que);
  }
}

int pushArrayQueue(ArrayQueue* que, pTreeNode e) {
  if ((que->rear + 1) % MAXQUEUE == que->front) {
    printf("is full\n");
    return -1;
  }

  que->rear = (que->rear + 1) % MAXQUEUE;
  que->data[que->rear] = e;

  return 0;
}

int popArrayQueue(ArrayQueue* que, pTreeNode* e) {
  if (que->front == que->rear) {
    printf("is empty\n");
    return -1;
  }

  que->front = (que->front + 1) % MAXQUEUE;
  *e = que->data[que->front];

  return 0;
}
