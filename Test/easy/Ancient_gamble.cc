#include <iostream>
using namespace std;

const int maxn = 5e5;
float ans;
const int n = 3;
float a[n];

void check() {
  int count = 0;
  int k = rand() % 6 + 1;
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 6 + 1;
    if (a[i] == k) count += 1;
  }

  if (count == 0) ans += 1;
  if (count == 1) ans -= 1;
  if (count == 2) ans -= 2;
  if (count == 3) ans -= 6;
}

int main(void) {
  srand(time(NULL));
  for (int i = 0; i < maxn; i++) check();
  printf("%.3f\n", ans / maxn);
  return 0;
}