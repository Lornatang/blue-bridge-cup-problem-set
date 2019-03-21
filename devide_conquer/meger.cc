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
/**
 *
ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
  if (pHead1 == NULL) {
    return pHead2;
  } else if (pHead2 == NULL) {
    return pHead1;
  }
  // 2个链表都不为空链表
  else {
    if (0) {
      ///////////////递归实现///////////////

      ListNode *pMerge = NULL;

      if (pHead1->val < pHead2->val) {
        pMerge = pHead1;
        pMerge->next = Merge(pHead1->next, pHead2);
      } else {
        pMerge = pHead2;
        pMerge->next = Merge(pHead2->next, pHead1);
      }

      return pMerge;
    } else {
      ///////////////非递归实现///////////////
      ListNode *pMerge = NULL;
      ListNode *pCur = NULL;

      while (pHead1 != NULL && pHead2 != NULL) {
        if (pHead1->val < pHead2->val) {
          if (pMerge == NULL) {
            pMerge = pCur = pHead1;
          } else {
            pCur->next = pHead1;
            pCur = pCur->next;
          }
          pHead1 = pHead1->next;
        } else {
          if (pMerge == NULL) {
            pMerge = pCur = pHead2;
          } else {
            pCur->next = pHead2;
            pCur = pCur->next;
          }
          pHead2 = pHead2->next;
        }
      }
      if (pHead1 == NULL) {
        pCur->next = pHead2;
      }
      if (pHead2 == NULL) {
        pCur->next = pHead1;
      }

      return pMerge;
    }
  }
}
*/
int main(void) { return 0; }
