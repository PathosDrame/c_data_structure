#include "linkQueue.h"

LinkQueue* createLinkQueue() {
  LinkQueue* que = (LinkQueue*)malloc(sizeof(LinkQueue));

  if (que == NULL) {
    printf("create link queue malloc failed\n");
    return NULL;
  }

  que->cnt = 0;
  que->front = que->rear = NULL;

  return que;
}

void releaseLinkQueue(LinkQueue* que) {
  if (que) {
    while (que->front) {
      Node* tmp = que->front;
      que->front = tmp->next;
      free(tmp);
      --que->cnt;
    }
    printf("node free: %d", que->cnt);
    free(que);
  }
}

int pushLinkQueue(LinkQueue* que, Element e) {
  Node* node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    printf("create node malloc failed\n");
    return -1;
  }

  node->elem = e;
  node->next = NULL;

  if (que->rear) {
    que->rear->next = node;
    que->rear = node;
  } else {
    que->rear = que->front = node;
  }

  ++que->cnt;

  return 0;
}

int popLinkQueue(LinkQueue* que, Element* e) {
  if (que->front == NULL) {
    printf("pop failed\n");
    return -1;
  }

  *e = que->front->elem;
  Node* tmp = que->front;
  que->front = tmp->next;
  free(tmp);
  --que->cnt;

  if (que->front == NULL) {
    que->front = que->rear = NULL;
  }

  return 0;
}
