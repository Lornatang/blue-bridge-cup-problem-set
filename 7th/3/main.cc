#include <stdio.h>
#include <algorithm>

int ans = 0;
int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void solve() {
  double sum = (double)num[0] + (double)num[1] / num[2] +
               (double)(num[3] * 100 + num[4] * 10 + num[5]) /
                   (num[6] * 100 + num[7] * 10 + num[8]);

  if (sum == 10) ans++;
}

int main() {
  while (std::next_permutation(num, num + 9)) solve();
  printf("%d\n", ans);
  return 0;
}