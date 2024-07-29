#include "threadedBtree.h"

ThreadedBTree* initTree() {
  TBTNode* nodeA = createTBTNode('A');
  TBTNode* nodeB = createTBTNode('B');
  TBTNode* nodeC = createTBTNode('C');
  TBTNode* nodeD = createTBTNode('D');
  TBTNode* nodeE = createTBTNode('E');
  TBTNode* nodeF = createTBTNode('F');
  TBTNode* nodeG = createTBTNode('G');
  TBTNode* nodeH = createTBTNode('H');
  TBTNode* nodeJ = createTBTNode('J');

  ThreadedBTree* tree = createThreadedBTree(nodeA);

  insertThreadedBTree(tree, nodeA, nodeB, nodeE);
  insertThreadedBTree(tree, nodeB, NULL, nodeC);
  insertThreadedBTree(tree, nodeE, NULL, nodeF);
  insertThreadedBTree(tree, nodeC, nodeD, NULL);
  insertThreadedBTree(tree, nodeF, nodeG, NULL);
  insertThreadedBTree(tree, nodeG, nodeH, nodeJ);
  return tree;
}

int main(int argc, char const* argv[]) {
  ThreadedBTree* tree = initTree();

  inOrderThreadedTree(tree);

  inOrderTBTree(tree);

  releaseThreadedBTree(tree);
  return 0;
}
