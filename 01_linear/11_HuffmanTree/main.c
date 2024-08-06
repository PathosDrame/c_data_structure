#include "huffmantree.h"

int main(int argc, char const* argv[]) {
  int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
  char show[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

  int size = sizeof(w) / sizeof(w[0]);
  HuffmanTree tree = createHuffmanTree(w, size);

  if (tree) {
    for (int i = 1; i <= 15; ++i) {
      printf("%d %d %d %d %d\n", i, tree[i].weight, tree[i].parent,
             tree[i].lChild, tree[i].rChild);
    }
  }

  HuffmanCode* code = createHuffmanCode(tree, size);
  for (int i = 0; i < sizeof(w) / sizeof(w[0]); ++i) {
    printf("%c: %s\n", show[i], code[i]);
  }
  releaseHuffmanCode(code, size);
  releaseHuffmanTree(tree);
  return 0;
}
