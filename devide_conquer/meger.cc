#include <iostream>

const int maxn = 1e3;

struct List {
  int data;
  List *next;
};

List *init(List *L) {
  L = (List *)malloc(sizeof(List) * maxn);
  if (L == NULL) printf("Opps! space is none!\n");
  L->next = NULL;
  return L;
}

List *insert(List *L, int data) {
  List *p;
  p->data = data;
  p->next = L->next;
  L->next = p;

  return L;
}

int main(void) {
  List *L;
  init(L);
  insert(L, 2);
  insert(L, 3);
  insert(L, 4);

  List *p;

  for (p = L->next; p != L; p = p->next) printf("%d ", p->data);
  return 0;
}
