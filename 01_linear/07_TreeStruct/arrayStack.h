#include "binaryTree.h"

#define MAXSIZE 20

typedef struct {
  pTreeNode data[MAXSIZE];
  int top;
} ArrayStack;

ArrayStack* createArrayStack();

void releaseArrayStack(ArrayStack* stack);

int pushArrayStack(ArrayStack* stack, pTreeNode e);

int popArrayStack(ArrayStack* stack, pTreeNode* e);
