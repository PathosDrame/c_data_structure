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

static Node* insertBSTNodeRecur(BST* bst, Node* node, Element e) {
  if (node == NULL) {
    bst->count++;
    return createNode(e);
  }
  if (e < node->data) {
    node->left = insertBSTNodeRecur(bst, node->left, e);
  } else if (e > node->data) {
    node->right = insertBSTNodeRecur(bst, node->right, e);
  }
  return node;
}

void insertBSTRecur(BST* bst, Element elem) {
  bst->root = insertBSTNodeRecur(bst, bst->root, elem);
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

static void deleteMinNode(Node* node) {
  Node* mini = node->right;
  Node* pre = node;
  while (mini && mini->left) {
    pre = mini;
    mini = mini->left;
  }
  node->data = mini->data;
  if (pre->data == node->data) {
    pre->right = mini->right;
  } else {
    pre->left = mini->right;
  }
  free(mini);
}

void deleteBSTNoRecur(BST* bst, Element elem) {
  Node* node = bst->root;
  Node* pre = NULL;
  Node* tmp = NULL;
  while (node) {
    if (elem < node->data) {
      pre = node;
      node = node->left;
    } else if (elem > node->data) {
      pre = node;
      node = node->right;
    } else {
      break;
    }
  }

  if (pre && node) {
    if (node->left == NULL) {
      tmp = node->right;
    } else if (node->right == NULL) {
      tmp = node->left;
    } else {
      deleteMinNode(node);
      bst->count--;
      return;
    }

    if (node->data < pre->data) {
      pre->left = tmp;
    } else {
      pre->right = tmp;
    }
    free(node);
    bst->count--;
    return;
  }

  if (pre == NULL) {
    deleteMinNode(node);
    bst->count--;
  }
}

int heightBSNode(Node* node) {
  if (node == NULL) {
    return 0;
  }
  int left = heightBSNode(node->left);
  int right = heightBSNode(node->right);
  if (left > right) {
    return left + 1;
  } else {
    return right + 1;
  }
}
