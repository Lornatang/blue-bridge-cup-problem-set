#include <iostream>

// recursive function
int recursive_binary_search(int *a, int l, int r, int target) {
  int middle = (l + r) / 2;
  if (target == a[middle]) return middle;

  if (target < a[middle])
    return recursive_binary_search(a, l, middle - 1, target);
  if (target > a[middle])
    return recursive_binary_search(a, middle + 1, r, target);
  return 0;
}

// loop
int loop_binary_search(int *a, int l, int r, int target) {
  while (l < r) {
    int middle = (l + r) / 2;
    if (target == a[middle])
      return middle;

    else if (target < a[middle])
      r = middle;

    else if (target > a[middle])
      l = middle + 1;
  }
  return 0;
}

int main() {
  int s[6] = {1, 2, 3, 4, 5, 6};
  int tar = loop_binary_search(s, 0, 6, 2);
  printf("%d\n", tar + 1);
  int tars = recursive_binary_search(s, 0, 6, 2);
  printf("%d\n", tars + 1);
  return 0;
}