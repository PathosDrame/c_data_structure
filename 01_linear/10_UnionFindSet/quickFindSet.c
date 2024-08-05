#include "quickFindSet.h"



QuickFindSet* createQuickFindSet(int size) {
  QuickFindSet* set = (QuickFindSet*)malloc(sizeof(QuickFindSet));

  set->size = size;
  set->data = (Element*)malloc(sizeof(Element) * size);
  set->groupId = (Element*)malloc(sizeof(Element) * size);

  return set;
}

void releaseQuickFindSet(QuickFindSet* setQF) {
  if (setQF) {
    if (setQF->data) {
      free(setQF->data);
    }
    if (setQF->groupId) {
      free(setQF->groupId);
    }
    free(setQF);
  }
}

void initQuickFindSet(QuickFindSet* setQF, const Element* data, int n) {
  for (int i = 0; i < n; i++) {
    setQF->data[i] = data[i];
    setQF->groupId[i] = i;
  }
}

static int findIndex(QuickFindSet* setQF, Element e) {
  for (int i = 0; i < setQF->size; ++i) {
    if (setQF->data[i] == e) {
      return i;
    }
  }
  return -1;
}

int isSameQF(QuickFindSet* setQF, Element a, Element b) {
  int aIndex = findIndex(setQF, a);
  int bIndex = findIndex(setQF, b);
  if (aIndex == -1 || bIndex == -1) {
    return 0;
  }
  return setQF->groupId[aIndex] == setQF->groupId[bIndex];
}

void unionQF(QuickFindSet* setQF, Element a, Element b) {
  int aIndex = findIndex(setQF, a);
  int bIndex = findIndex(setQF, b);
  int bGrpId = setQF->groupId[bIndex];
  for (int i = 0; i < setQF->size; ++i) {
    if (setQF->groupId[i] == bGrpId) {
      setQF->groupId[i] = setQF->groupId[aIndex];
    }
  }
}