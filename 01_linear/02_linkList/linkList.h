#include <stdio.h>
#include <stdlib.h>

/*
单向链表,带头节点
*/

typedef int Element;

// 节点
typedef struct node {
  Element elem;
  struct node* next;
} Node;

typedef struct {
  Node head;
  int len;
} LinkList;

LinkList* createLinkList();

void releaseLinkList(LinkList* list);

// 插入
int insertLinkList(LinkList* list, int pos, Element e);

// 删除节点
int deleteLinkList(LinkList* list, Element e);

void showLinkList(LinkList* list);