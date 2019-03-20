#include <algorithm>
#include <iostream>

const int maxn = 1e3 + 10;
int ne[maxn] = {0};

bool compare(int x, int y) { return x < y; }

int solve() {
  int t;
  scanf("%d", &t);  // 1

  int n;
  scanf("%d", &n);  // 4

  for (int i = 0; i < n; i++) scanf("%d", &ne[i]);  // 1 2 5 10

  int time = 0;

  std::sort(ne, ne + n, compare);

  if (n <= 3) {
    if (n == 1) time = ne[0];
    if (n == 2) time = ne[1];
    if (n == 3) time = ne[0] + ne[1] + ne[2];
  } else {
    for (int i = n - 1; i > 1; i -= 2)
      if (i >= 3)
        if (ne[0] + ne[i - 1] >= 2 * ne[1])
          time += ne[1] + ne[0] + ne[i] + ne[1];
        else
          time += ne[i] + ne[0] + ne[i - 1] + ne[0];
      else
        time += ne[2] + ne[0];
    time += ne[1];
  }

  return time;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", solve());
  return 0;
}
