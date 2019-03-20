#include <iostream>

#define M 10007
const int maxn = 1e6;
int cnt;

int solve(int n) {
  long long f1 = 1, f2 = 1;

  for (int i = 1; i <= n; i++) {
    cnt = f1 % M;
    long long temp = f2;
    f2 = (f1 + f2) % M;
    f1 = temp;
  }
  return cnt;
}

int main() {
  long long n;
  scanf("%lld", &n);

  printf("%d\n", solve(n));

  return 0;
}
