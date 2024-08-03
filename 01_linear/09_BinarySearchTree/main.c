#include "BSearchTree.h"

void t01() {
  Element data[] = {55, 33, 45, 100, 22, 80, 8, 130};
  BST *bst = createBST();
  if (bst == NULL) {
    printf("bst is null\n");
    return;
  }
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    insertBSTNoRecur(bst, data[i]);
  }
  inOrderBST(bst);

  releaseBST(bst);
}

void linearFindTest(Element *data, int n, int cnt, Element val) {
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < n; j++) {
      if (data[j] == val) {
        printf("find %d\n", val);
        return;
      }
    }
  }
}

void binaryFindTest(BST *bst, int cnt, Element val) {
  Node *node = NULL;
  for (int i = 0; i < cnt; i++) {
    node = searchBST(bst, val);
    if (node) {
      printf("find %d\n", val);
    }
  }
}

void t02() {
  int n = 100000;
  Element m = n + 50000;
  int cnt = 10000;
  Element *data = (Element *)malloc(sizeof(Element) * n);

  clock_t start, end;

  srand(time(NULL));
  for (int i = 0; i < n; ++i) {
    data[i] = rand() % m;
  }

  start = clock();
  linearFindTest(data, n, cnt, m + 10);
  end = clock();
  printf("linearFindTest: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
  BST *bst = createBST();
  for (int i = 0; i < n; ++i) {
    insertBSTNoRecur(bst, data[i]);
  }

  start = clock();
  binaryFindTest(bst, cnt, m + 10);
  end = clock();
  printf("binaryFindTest: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void t03() {
  Element data[] = {55, 33, 45, 100, 22, 80, 8, 130, 120};
  BST *bst = createBST();
  if (bst == NULL) {
    printf("bst is null\n");
    return;
  }
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    insertBSTNoRecur(bst, data[i]);
  }
  inOrderBST(bst);

  printf("\n");

  deleteBSTNoRecur(bst, 8);
  inOrderBST(bst);

  printf("\n");

  deleteBSTNoRecur(bst, 100);
  inOrderBST(bst);

  printf("\n");

  deleteBSTNoRecur(bst, 55);
  inOrderBST(bst);

  releaseBST(bst);
}

void t04() {
  Element data[] = {55, 33, 45, 100, 22, 80, 8, 130, 120};
  BST *bst = createBST();
  if (bst == NULL) {
    printf("bst is null\n");
    return;
  }
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    insertBSTRecur(bst, data[i]);
  }

  inOrderBST(bst);

  int h = heightBSNode(bst->root);
  printf("height: %d\n", h);

  releaseBST(bst);
}

int main(int argc, char const *argv[]) {
  t01();

  t02();

  t03();

  t04();
  return 0;
}
