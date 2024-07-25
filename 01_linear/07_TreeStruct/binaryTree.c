#include "binaryTree.h"

BinaryTree* createBinaryTree(TreeNode* root) {
  BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
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

TreeNode* createTreeNode(Element e) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  if (node == NULL) {
    fprintf(stderr, "node malloc failed\n");
    return NULL;
  }

  node->data = e;
  node->left = node->right = NULL;

  return node;
}

void insertBinaryTree(BinaryTree* root, TreeNode* parent, TreeNode* left,
                      TreeNode* right) {
  if (root && parent) {
    parent->right = right;
    parent->left = left;
    if (left) {
      ++root->count;
    }
    if (right) {
      ++root->count;
    }
  }
}

static void preOrder(TreeNode* node) {
  if (node) {
    visitTreeNode(node);
    preOrder(node->left);
    preOrder(node->right);
  }
}

void preOrderBTreeRecur(BinaryTree* tree) {
  if (tree) {
    preOrder(tree->root);
    printf("\n");
  }
}

static void midOrder(TreeNode* node) {
  if (node) {
    midOrder(node->left);
    visitTreeNode(node);
    midOrder(node->right);
  }
}

void midOrderBtreeRecur(BinaryTree* tree) {
  if (tree) {
    midOrder(tree->root);
    printf("\n");
  }
}

static void afterOrder(TreeNode* node) {
  if (node) {
    afterOrder(node->left);
    afterOrder(node->right);
    visitTreeNode(node);
  }
}

void afterOrderBtreeRecur(BinaryTree* tree) {
  if (tree) {
    afterOrder(tree->root);
    printf("\n");
  }
}

void visitTreeNode(TreeNode* node) { printf("%c\t", node->data); }
