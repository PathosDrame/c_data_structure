#ifndef Union
#define Union

#include "common.h"

typedef struct {
  Element *data;
  int *parent;
  int n;
  int *size;
} QuickUnionSet;

typedef struct setNode {
  int idx;
  struct setNode *next;
} SetNode;

QuickUnionSet *createQuickUnionSet(int n);

void releaseQuickUnionSet(QuickUnionSet *setQU);

void initQuickUnionSet(QuickUnionSet *setQU, const Element *data, int n);

int isSameQU(QuickUnionSet *setQU, Element a, Element b);

void unionQU(QuickUnionSet *setQU, Element a, Element b);
#endif
