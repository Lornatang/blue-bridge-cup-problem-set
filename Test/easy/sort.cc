#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5;
int arr[maxn];

bool compare(int i, int j) { return i < j; }

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  sort(arr, arr + n, compare);
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
  return 0;
}