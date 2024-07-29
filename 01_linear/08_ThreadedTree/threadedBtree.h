#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct treeNode {
  Element data;
  struct treeNode* left;
  struct treeNode* right;
  int lTag;
  int rTag;
} TBTNode;

typedef struct {
  TBTNode* root;
  int count;
} ThreadedBTree;

ThreadedBTree* createThreadedBTree(TBTNode* root);

void releaseThreadedBTree(ThreadedBTree* tree);

TBTNode* createTBTNode(Element e);

void insertThreadedBTree(ThreadedBTree* tree, TBTNode* parent, TBTNode* left,
                         TBTNode* right);

void visitTBTNode(TBTNode* node);

void inOrderThreadedTree(ThreadedBTree* tree);

void inOrderTBTree(ThreadedBTree* tree);