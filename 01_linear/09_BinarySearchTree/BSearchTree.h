#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Element;

typedef struct Node {
  Element data;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct {
  Node *root;
  int count;
} BST;

BST *createBST();

void releaseBST(BST *bst);

void insertBSTNoRecur(BST *bst, Element elem);

void insertBSTRecur(BST *bst, Element elem);

Node *searchBST(BST *bst, Element elem);

void inOrderBST(BST *bst);

int heightBST(BST *bst);

void deleteBSTNoRecur(BST *bst, Element elem);

int heightBSNode(Node *node);
