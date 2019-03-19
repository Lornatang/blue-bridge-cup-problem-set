#include <iostream>
using namespace std;

const int maxn = 110;
int x[maxn];

bool check(int n) {
  if (n == 1) return false;

  if (n > 1 && check(n - 1) == false) return true;
  if (n > 3 && check(n - 3) == false) return true;
  if (n > 7 && check(n - 7) == false) return true;
  if (n > 8 && check(n - 8) == false) return true;

  return false;
}

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", &x[i]);

  printf("\n");

  for (int i = 0; i < n; i++) printf("%d\n", check(x[i]));
  return 0;
}