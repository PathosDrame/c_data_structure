#include "seqList.h"

// 产生容量为n个元素的顺序表
SeqList* createSeqList(int cap) {
  SeqList* seq = (SeqList*)malloc(sizeof(SeqList));
  if (seq == NULL) {
    printf("create malloc error\n");
    return NULL;
  }

  seq->elem = (Element*)malloc(sizeof(Element) * cap);
  for (int i = 0; i < cap; ++i) {
    seq->elem[i] = 0;
  }
  seq->len = 0;
  seq->cap = cap;

  return seq;
}

// 释放顺序表
void releaseSeqList(SeqList* seq) {
  if (seq) {
    if (seq->elem) {
      free(seq->elem);
    }
    free(seq);
  }
}

// 获取顺序表中某个位置的值
int getSeqList(SeqList* seq, int pos, int* val) {
  if (pos < 1 || pos > seq->len) {
    printf("get pos invalid\n");
    return -1;
  }

  *val = seq->elem[pos - 1];
  return 0;
}

// 查找顺序表中的元素
int locateSeqList(SeqList* seq, Element val) {
  for (int i = 0; i < seq->len; ++i) {
    if (seq->elem[i] == val) {
      return i + 1;
    }
  }
  return -1;
}

// 向顺序表指定位置插入元素
int insertSeqList(SeqList* seq, int pos, Element val) {
  if (pos < 1 || pos > seq->len + 1) {
    printf("insert pos invalid\n");
    return -1;
  }

  // 容量是否满足
  if (seq->len + 1 > seq->cap) {
    printf("enlarger!\n");
    Element* tmp = (Element*)malloc(sizeof(Element) * seq->cap * 2);
    if (tmp == NULL) {
      printf("insert malloc error\n");
      return -1;
    }

    for (int i = 0; i < seq->len; ++i) {
      tmp[i] = seq->elem[i];
    }
    seq->cap = seq->cap * 2;
    free(seq->elem);
    seq->elem = tmp;
  }

  // 将pos位置后面的元素往后移动
  for (int i = seq->len - 1; i >= pos - 1; --i) {
    seq->elem[i + 1] = seq->elem[i];
  }

  seq->elem[pos - 1] = val;
  ++seq->len;

  return 0;
}

// 遍历
void showSeqList(SeqList* seq) {
  for (int i = 0; i < seq->len; ++i) {
    printf("%d\t", seq->elem[i]);
  }
  printf("\n");
}

// 从顺序表中指定位置删除
int deleteSeqList(SeqList* seq, int pos) {
  if (pos < 1 || pos > seq->len) {
    printf("delete pos invalid\n");
    return -1;
  }

  for (int i = pos; i < seq->len; ++i) {
    seq->elem[i - 1] = seq->elem[i];
  }

  --seq->len;

  return 0;
}
