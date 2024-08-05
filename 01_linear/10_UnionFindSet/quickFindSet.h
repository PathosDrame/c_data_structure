#ifndef Find
#define Find

#include "common.h"

typedef struct {
  Element *data;
  int size;
  int *groupId;
} QuickFindSet;

QuickFindSet *createQuickFindSet(int size);

void releaseQuickFindSet(QuickFindSet *setQF);

void initQuickFindSet(QuickFindSet *setQF, const Element *data, int n);

int isSameQF(QuickFindSet *setQF, Element a, Element b);

void unionQF(QuickFindSet *setQF, Element a, Element b);
#endif