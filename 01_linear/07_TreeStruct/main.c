#include "binaryTree.h"

BinaryTree* initTree() {
  TreeNode* nodeA = createTreeNode('A');
  TreeNode* nodeB = createTreeNode('B');
  TreeNode* nodeC = createTreeNode('C');
  TreeNode* nodeD = createTreeNode('D');
  TreeNode* nodeE = createTreeNode('E');
  TreeNode* nodeF = createTreeNode('F');
  TreeNode* nodeG = createTreeNode('G');
  TreeNode* nodeH = createTreeNode('H');
  TreeNode* nodeJ = createTreeNode('J');

  BinaryTree* tree = createBinaryTree(nodeA);

  insertBinaryTree(tree, nodeA, nodeB, nodeE);
  insertBinaryTree(tree, nodeB, NULL, nodeC);
  insertBinaryTree(tree, nodeE, NULL, nodeF);
  insertBinaryTree(tree, nodeC, nodeD, NULL);
  insertBinaryTree(tree, nodeF, nodeG, NULL);
  insertBinaryTree(tree, nodeG, nodeH, nodeJ);
  return tree;
}

int main(int argc, char const* argv[]) {
  BinaryTree* tree = initTree();
  preOrderBTreeRecur(tree);
  midOrderBtreeRecur(tree);
  afterOrderBtreeRecur(tree);
  levelOrderBTree(tree);

  printf("\n");
  preOrderBTreeNoRecur(tree);
  inOrderBTreeNoRecur(tree);
  printf("\n");
  postOrderBTreeNoRecur(tree);

  releaseBinaryTree(tree);

  return 0;
}
