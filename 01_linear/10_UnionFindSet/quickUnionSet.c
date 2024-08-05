#include "quickUnionSet.h"

QuickUnionSet* createQuickUnionSet(int n) {
  QuickUnionSet* setQU = (QuickUnionSet*)malloc(sizeof(QuickUnionSet));

  setQU->data = (Element*)malloc(sizeof(Element) * n);
  setQU->size = (int*)malloc(sizeof(int) * n);
  setQU->parent = (int*)malloc(sizeof(int) * n);
  setQU->n = n;

  return setQU;
}

void releaseQuickUnionSet(QuickUnionSet* setQU) {
  if (setQU) {
    if (setQU->data) {
      free(setQU->data);
    }
    if (setQU->size) {
      free(setQU->size);
    }
    if (setQU->parent) {
      free(setQU->parent);
    }
    free(setQU);
  }
}

void initQuickUnionSet(QuickUnionSet* setQU, const Element* data, int n) {
  for (int i = 0; i < setQU->n; ++i) {
    setQU->data[i] = data[i];
    setQU->parent[i] = i;
    setQU->size[i] = 1;
  }
}

static int findIndex(QuickUnionSet* setQU, Element e) {
  for (int i = 0; i < setQU->n; ++i) {
    if (setQU->data[i] == e) {
      return i;
    }
  }
  return -1;
}

static int findRootIndexNormal(QuickUnionSet* setQU, Element e) {
  int curIndex = findIndex(setQU, e);
  while (setQU->parent[curIndex] != curIndex) {
    curIndex = setQU->parent[curIndex];
  }
  return curIndex;
}

static SetNode* push(SetNode* stack, int idx) {
  SetNode* node = (SetNode*)malloc(sizeof(SetNode));
  node->idx = idx;
  node->next = stack;
  return node;
}

static SetNode* pop(SetNode* stack, int* idx) {
  SetNode* tmp = stack;
  *idx = stack->idx;
  stack = tmp->next;
  free(stack);
  return stack;
}

static int findRootIndex(QuickUnionSet* setQU, Element e) {
  int curIndex = findIndex(setQU, e);
  if (curIndex == -1) {
    return -1;
  }
  SetNode* path = NULL;
  while (setQU->parent[curIndex] != curIndex) {
    path = push(path, curIndex);
    curIndex = setQU->parent[curIndex];
  }
  while (path) {
    int pos;
    path = pop(path, &pos);
    setQU->parent[pos] = curIndex;
  }
  return curIndex;
}

int isSameQU(QuickUnionSet* setQU, Element a, Element b) {
  int aRoot = findRootIndex(setQU, a);
  int bRoot = findRootIndex(setQU, b);
  if (aRoot == -1 || bRoot == -1) {
    return 0;
  }
  return aRoot == bRoot;
}

void unionQU(QuickUnionSet* setQU, Element a, Element b) {
  int aRoot = findRootIndex(setQU, a);
  int bRoot = findRootIndex(setQU, b);
  if (aRoot == -1 || bRoot == -1) {
    return;
  }
  if (aRoot != bRoot) {
    int aSize = setQU->size[aRoot];
    int bSize = setQU->size[bRoot];
    if (aSize >= bSize) {
      setQU->parent[bRoot] = aRoot;
      setQU->size[aRoot] += bSize;
    } else {
      setQU->parent[aRoot] = bRoot;
      setQU->size[bRoot] += aSize;
    }
  }
}
