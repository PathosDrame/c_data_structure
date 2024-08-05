
#include <stdio.h>
#include <stdlib.h>

#include "quickFindSet.h"
#include "quickUnionSet.h"

int t01() {
  int size = 9;
  QuickFindSet* QFset = createQuickFindSet(size);
  Element data[9];
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
    data[i] = i;
  }

  initQuickFindSet(QFset, data, size);
  unionQF(QFset, 3, 4);
  unionQF(QFset, 8, 0);
  unionQF(QFset, 2, 3);
  unionQF(QFset, 5, 6);
  if (isSameQF(QFset, 0, 2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  if (isSameQF(QFset, 2, 4)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  unionQF(QFset, 5, 1);
  unionQF(QFset, 7, 3);
  unionQF(QFset, 1, 6);
  unionQF(QFset, 4, 8);

  if (isSameQF(QFset, 0, 2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  if (isSameQF(QFset, 2, 4)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  releaseQuickFindSet(QFset);
  return 0;
}

int t02() {
  int n = 9;
  QuickUnionSet* QUset = createQuickUnionSet(n);
  Element data[9];
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
    data[i] = i;
  }
  initQuickUnionSet(QUset, data, n);
  unionQU(QUset, 3, 4);
  unionQU(QUset, 8, 0);
  unionQU(QUset, 2, 3);
  unionQU(QUset, 5, 6);
  if (isSameQU(QUset, 0, 2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  if (isSameQU(QUset, 2, 4)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  unionQU(QUset, 5, 1);
  unionQU(QUset, 7, 3);
  unionQU(QUset, 1, 6);
  unionQU(QUset, 4, 8);

  if (isSameQU(QUset, 0, 2)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  if (isSameQU(QUset, 2, 4)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  releaseQuickUnionSet(QUset);
  return 0;
}

int main(int argc, char const* argv[]) {
  t01();
  t02();
  return 0;
}
