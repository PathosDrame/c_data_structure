#include "BSearchTree.h"

BST* createBST() {
  BST* tree = (BST*)malloc(sizeof(BST));
  if (tree == NULL) {
    printf("Error: out of memory\n");
    exit(1);
  }

  tree->count = 0;
  tree->root = NULL;

  return tree;
}

static void freeNode(BST* bst, Node* node) {
  if (node == NULL) {
    return;
  }

  freeNode(bst, node->left);
  freeNode(bst, node->right);
  free(node);
  --bst->count;
}

void releaseBST(BST* bst) {
  if (bst) {
    freeNode(bst, bst->root);
    printf("BST have %d node\n", bst->count);
    free(bst);
  }
}

static Node* createNode(Element elem) {
  Node* node = (Node*)malloc(sizeof(Node));

  if (node == NULL) {
    printf("malloc failed\n");
    return NULL;
  }

  node->data = elem;
  node->left = node->right = NULL;

  return node;
}

void insertBSTNoRecur(BST* bst, Element elem) {
  Node* cur = bst->root;
  Node* pre = NULL;

  while (cur) {
    pre = cur;
    if (elem < cur->data) {
      cur = cur->left;
    } else if (elem > cur->data) {
      cur = cur->right;
    } else {
      return;
    }
  }

  Node* node = createNode(elem);

  if (node == NULL) {
    printf("malloc failed");
    return;
  }

  if (cur == NULL) {
    if (pre && pre->data > elem) {
      pre->left = node;
    } else if (pre && pre->data < elem) {
      pre->right = node;
    }
  }

  if (pre == NULL) {
    bst->root = node;
  }

  ++bst->count;
}

Node* searchBST(BST* bst, Element elem) {
  Node* node = bst->root;

  while (node) {
    if (elem < node->data) {
      node = node->left;
    } else if (elem > node->data) {
      node = node->right;
    } else {
      return node;
    }
  }

  return NULL;
}

static void inOrder(Node* node) {
  if (node) {
    inOrder(node->left);
    printf("%d\t", node->data);
    inOrder(node->right);
  }
}

void inOrderBST(BST* bst) {
  if (bst && bst->root) {
    inOrder(bst->root);
  }
}

int heightBST(BST* bst) {
  int ans = 0;
  return ans;
}
