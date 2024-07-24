#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 5

typedef int Element;

typedef struct {
  Element data[MAXQUEUE];
  int front;
  int rear;
} ArrayQueue;

ArrayQueue* createArrayQueue();

void releaseArrayQueue(ArrayQueue* que);

int pushArrayQueue(ArrayQueue* que, Element e);

int popArrayQueue(ArrayQueue* que, Element* e);
