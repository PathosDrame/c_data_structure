

#include "seqList.h"

int main(int argc, char const* argv[]) {
  int n = 5;
  SeqList* seq = createSeqList(n);

  for (int i = 1; i <= n; ++i) {
    insertSeqList(seq, i, i);
  }

  showSeqList(seq);

  insertSeqList(seq, 3, 6);
  showSeqList(seq);

  insertSeqList(seq, 9, 9);
  showSeqList(seq);

  deleteSeqList(seq, 3);

  showSeqList(seq);

  int* val;
  getSeqList(seq, 1, val);
  printf("val: %d\n", *val);

  int pos = locateSeqList(seq, 5);
  printf("pos: %d\n", pos);

  releaseSeqList(seq);
  return 0;
}
