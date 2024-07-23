#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef int Element;

typedef struct {
  Element data[MAXSIZE];
  int top;
} ArrayStack;

ArrayStack* createArrayStack();

void releaseArrayStack(ArrayStack* stack);

int pushArrayStack(ArrayStack* stack, Element e);

int popArrayStack(ArrayStack* stack, Element* e);
