#include "binaryTree.h"

#include "arrayQueue.h"
#include "arrayStack.h"

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

static void destroyTreeNode(BinaryTree* root, TreeNode* node) {
  if (node) {
    destroyTreeNode(root, node->left);
    destroyTreeNode(root, node->right);
    free(node);
    --root->count;
  }
}

void releaseBinaryTree(BinaryTree* root) {
  if (root) {
    destroyTreeNode(root, root->root);
    printf("tree have %d node\n", root->count);
    free(root);
  }
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

void levelOrderBTree(BinaryTree* tree) {
  ArrayQueue* que = createArrayQueue();
  pushArrayQueue(que, tree->root);
  pTreeNode node;
  while (popArrayQueue(que, &node) != -1) {
    visitTreeNode(node);
    if (node->left) {
      pushArrayQueue(que, node->left);
    }
    if (node->right) {
      pushArrayQueue(que, node->right);
    }
  }
  releaseArrayQueue(que);
}

void preOrderBTreeNoRecur(BinaryTree* tree) {
  if (tree->root) {
    ArrayStack* stack = createArrayStack();
    pTreeNode node = tree->root;
    pushArrayStack(stack, node);
    while (popArrayStack(stack, &node) != -1 && node) {
      visitTreeNode(node);
      if (node->right) {
        pushArrayStack(stack, node->right);
      }
      if (node->left) {
        pushArrayStack(stack, node->left);
      }
    }
    releaseArrayStack(stack);
  }
}

void inOrderBTreeNoRecur(BinaryTree* tree) {
  if (tree->root) {
    ArrayStack* stack = createArrayStack();
    pTreeNode node = tree->root;
    while (stack->top >= 0 || node) {
      if (node) {
        pushArrayStack(stack, node);
        node = node->left;
      } else {
        popArrayStack(stack, &node);
        visitTreeNode(node);
        node = node->right;
      }
    }
    releaseArrayStack(stack);
  }
}

void postOrderBTreeNoRecur(BinaryTree* tree) {
  if (tree) {
    ArrayStack* stack1 = createArrayStack();
    ArrayStack* stack2 = createArrayStack();

    TreeNode* node;
    pushArrayStack(stack1, tree->root);
    while (popArrayStack(stack1, &node) != -1) {
      pushArrayStack(stack2, node);
      if (node->left) {
        pushArrayStack(stack1, node->left);
      }
      if (node->right) {
        pushArrayStack(stack1, node->right);
      }
    }
    while (popArrayStack(stack2, &node) != -1) {
      visitTreeNode(node);
    }

    releaseArrayStack(stack1);
    releaseArrayStack(stack2);
  }
}
