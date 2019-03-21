#include <iostream>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void quick_sort(int *a, int start, int end) {
  if (start < end) {
    int l = start, r = end, x = a[l];
    while (l < r) {
      while (l < r && a[r] >= x) r--;
      if (l < r) swap(&a[l++], &a[r]);

      while (l < r && a[l] < x) l++;
      if (l < r) swap(&a[r--], &a[l]);
    }
    a[l] = x;
    quick_sort(a, start, l - 1);
    quick_sort(a, l + 1, end);
  }
}

int main(void) {
  int s[11] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  quick_sort(s, 0, 10);
  for (int i = 0; i < 11; i++) printf("%d ", s[i]);
  printf("\n");
  return 0;
}
