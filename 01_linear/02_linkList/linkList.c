#include "linkList.h"

LinkList* createLinkList() {
  LinkList* list = (LinkList*)malloc(sizeof(LinkList));
  if (list == NULL) {
    printf("create list malloc failed\n");
    return NULL;
  }

  list->head.elem = 0x88;
  list->head.next = NULL;
  list->len = 0;

  return list;
}

void releaseLinkList(LinkList* list) {
  if (list) {
    // 遍历链表的每个元素依次释放
    Node* node = &list->head;
    int cnt = 0;
    while (node->next) {
      Node* tmp = node->next;
      node->next = tmp->next;
      free(tmp);
      ++cnt;
    }
    printf("release %d node\n", cnt);
    free(list);
  }
}

int insertLinkList(LinkList* list, int pos, Element e) {
  if (pos < 1 || pos > list->len + 1) {
    printf("insert pos failed\n");
    return -1;
  }

  // 找到pos - 1的位置,进行插入
  int cnt = 0;
  Node* tmp = &list->head;
  while (tmp && cnt < pos - 1) {
    tmp = tmp->next;
    ++cnt;
  }

  // tmp指向了待插入位置的前一个节点
  Node* node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    printf("malloc node failed\n");
    return -1;
  }

  node->elem = e;
  node->next = tmp->next;
  tmp->next = node;
  ++list->len;

  return 0;
}

int deleteLinkList(LinkList* list, Element e) {
  Node* node = &list->head;

  while (node->next && node->next->elem != e) {
    node = node->next;
  }

  if (node->next == NULL) {
    printf("not found\n");
    return -1;
  }

  // 删除
  Node* tmp = node->next;
  node->next = tmp->next;
  free(tmp);

  return 0;
}

void showLinkList(LinkList* list) {
  Node* node = list->head.next;
  while (node) {
    printf("%d\t", node->elem);
    node = node->next;
  }
  printf("\n");
}
