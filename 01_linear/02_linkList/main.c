#include "linkList.h"
int main(int argc, char const* argv[]) {
  LinkList* list = createLinkList();

  if (list == NULL) {
    return -1;
  }

  for (int i = 1; i <= 5; ++i) {
    insertLinkList(list, i, i);
  }

  showLinkList(list);

  deleteLinkList(list, 3);

  showLinkList(list);

  releaseLinkList(list);

  return 0;
}
