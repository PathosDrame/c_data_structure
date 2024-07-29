#ifndef _BINARYTREE_
#define _BINARYTREE_
#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct treeNode {
  Element data;
  struct treeNode* left;
  struct treeNode* right;
} TreeNode;

typedef TreeNode* pTreeNode;

typedef struct {
  TreeNode* root;
  int count;
} BinaryTree;

BinaryTree* createBinaryTree(TreeNode* root);

void releaseBinaryTree(BinaryTree* root);

TreeNode* createTreeNode(Element e);

void insertBinaryTree(BinaryTree* root, TreeNode* parent, TreeNode* left,
                      TreeNode* right);

void preOrderBTreeRecur(BinaryTree* tree);

void midOrderBtreeRecur(BinaryTree* tree);

void afterOrderBtreeRecur(BinaryTree* tree);

void visitTreeNode(TreeNode* node);

void levelOrderBTree(BinaryTree* tree);

void preOrderBTreeNoRecur(BinaryTree* tree);

void inOrderBTreeNoRecur(BinaryTree* tree);

void postOrderBTreeNoRecur(BinaryTree* tree);

#endif