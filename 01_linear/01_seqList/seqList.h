#include <stdio.h>
#include <stdlib.h>

/*
 *   动态顺序
 */

typedef int Element;

typedef struct {
  Element* elem;  // 顺序表元素空间的首
  int len;        // 记录顺序表的元素个数
  int cap;        // 记录顺序表的容量
} SeqList;

// 产生容量为n个元素的顺序表
SeqList* createSeqList(int cap);

// 释放顺序表
void releaseSeqList(SeqList* seq);

// 获取顺序表中某个位置的值
int getSeqList(SeqList* seq, int pos, int* val);

// 查找顺序表中的元素
int locateSeqList(SeqList* seq, Element val);

// 向顺序表指定位置插入元素
int insertSeqList(SeqList* seq, int pos, Element val);

// 遍历
void showSeqList(SeqList* seq);

// 从顺序表中指定位置删除
int deleteSeqList(SeqList* seq, int pos);