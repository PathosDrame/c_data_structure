#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int weight;
  int lChild, rChild;
  int parent;
} HuffmanNode, *HuffmanTree;

HuffmanTree createHuffmanTree(const int* w, int n);

void releaseHuffmanTree(HuffmanTree tree);

typedef char* HuffmanCode;

HuffmanCode* createHuffmanCode(HuffmanTree tree, int n);
void releaseHuffmanCode(HuffmanCode* codes, int n);