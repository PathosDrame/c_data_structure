#include "threadedBtree.h"

ThreadedBTree* createThreadedBTree(TBTNode* root) {
  ThreadedBTree* tree = (ThreadedBTree*)malloc(sizeof(ThreadedBTree));
  if (tree == NULL) {
    fprintf(stderr, "tree malloc failed\n");
    return NULL;
  }

  if (root) {
    tree->root = root;
    tree->count = 1;
  } else {
    tree->root = NULL;
    tree->count = 0;
  }

  return tree;
}

static void freeTBTNode(ThreadedBTree* tree, TBTNode* node) {
  if (node) {
    if (!node->lTag) {
      freeTBTNode(tree, node->left);
    }
    if (!node->rTag) {
      freeTBTNode(tree, node->right);
    }
    free(node);
    --tree->count;
  }
}

void releaseThreadedBTree(ThreadedBTree* tree) {
  if (tree) {
    freeTBTNode(tree, tree->root);
    printf("tree have %d node\n", tree->count);
  }
}

TBTNode* createTBTNode(Element e) {
  TBTNode* node = (TBTNode*)malloc(sizeof(TBTNode));
  if (node == NULL) {
    fprintf(stderr, "node malloc failed\n");
    return NULL;
  }

  node->data = e;
  node->left = node->right = NULL;
  node->lTag = node->rTag = 0;

  return node;
}

void insertThreadedBTree(ThreadedBTree* tree, TBTNode* parent, TBTNode* left,
                         TBTNode* right) {
  if (tree && parent) {
    parent->left = left;
    parent->right = right;
    if (left) {
      ++tree->count;
    }
    if (right) {
      ++tree->count;
    }
  }
}

void visitTBTNode(TBTNode* node) {
  if (node) {
    printf("%c\t", node->data);
  }
}

static TBTNode* pre = NULL;

static void inOrderThreading(TBTNode* node) {
  if (node) {
    inOrderThreading(node->left);
    if (node->left == NULL) {
      node->lTag = 1;
      node->left = pre;
    }
    if (pre && pre->right == NULL) {
      pre->rTag = 1;
      pre->right = node;
    }
    pre = node;
    inOrderThreading(node->right);
  }
}

void inOrderThreadedTree(ThreadedBTree* tree) {
  if (tree) {
    inOrderThreading(tree->root);
  }
}

void inOrderTBTree(ThreadedBTree* tree) {
  TBTNode* node = tree->root;
  while (node) {
    while (node->lTag == 0) {
      node = node->left;
    }
    visitTBTNode(node);
    while (node->rTag && node->right) {
      node = node->right;
      visitTBTNode(node);
    }
    node = node->right;
  }
}
