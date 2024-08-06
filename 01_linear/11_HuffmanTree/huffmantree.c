#include "huffmantree.h"

static void selectNode(HuffmanTree tree, int n, int *s1, int *s2) {
  int min = 0;
  for (int i = 1; i <= n; ++i) {
    if (tree[i].parent == 0) {
      min = i;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (tree[i].parent == 0) {
      if (tree[i].weight < tree[min].weight) {
        min = i;
      }
    }
  }
  *s1 = min;
  for (int i = 1; i <= n; ++i) {
    if (tree[i].parent == 0 && i != *s1) {
      min = i;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (tree[i].parent == 0 && i != *s1) {
      if (tree[i].weight < tree[min].weight) {
        min = i;
      }
    }
  }
  *s2 = min;
}

HuffmanTree createHuffmanTree(const int *w, int n) {
  HuffmanTree tree;
  int m = 2 * n - 1;
  tree = (HuffmanTree)malloc(sizeof(HuffmanNode) * (m + 1));
  for (int i = 1; i <= m; ++i) {
    tree[i].parent = tree[i].lChild = tree[i].rChild = tree[i].weight = 0;
  }
  for (int i = 1; i <= n; ++i) {
    tree[i].weight = w[i - 1];
  }
  int s1, s2;
  for (int i = n + 1; i <= m; ++i) {
    selectNode(tree, i - 1, &s1, &s2);
    tree[s1].parent = tree[s2].parent = i;
    tree[i].lChild = s1;
    tree[i].rChild = s2;
    tree[i].weight = tree[s1].weight + tree[s2].weight;
  }
  return tree;
}

void releaseHuffmanTree(HuffmanTree tree) {
  if (tree) {
    free(tree);
  }
}

HuffmanCode *createHuffmanCode(HuffmanTree tree, int n) {
  char *temp = (char *)malloc(sizeof(char) * n);
  HuffmanCode *codes = (HuffmanCode *)malloc(sizeof(HuffmanCode) * n);
  memset(codes, 0, sizeof(HuffmanCode) * n);
  int start;
  int p;
  int pos;
  for (int i = 1; i <= n; ++i) {
    start = n - 1;
    temp[start] = '\0';
    pos = i;
    p = tree[i].parent;
    while (p) {
      --start;
      temp[start] = ((tree[p].lChild == pos) ? '0' : '1');
      pos = p;
      p = tree[p].parent;
    }
    codes[i - 1] = (HuffmanCode)malloc(sizeof(char) * (n - start));
    strcpy(codes[i - 1], &temp[start]);
  }
  free(temp);
  return codes;
}

void releaseHuffmanCode(HuffmanCode *codes, int n) {
  if (codes) {
    for (int i = 0; i < n; ++i) {
      if (codes[i]) {
        free(codes[i]);
      }
    }
    free(codes);
  }
}
