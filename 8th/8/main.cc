#include <stdio.h>

const int maxm = 100010;
const int maxn = 110;
int a[maxn];
int dp[maxm];
int cnt = 0;

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  int k = gcd(a[1], a[2]);
  for (int i = 3; i <= n; i++) k = gcd(k, a[i]);

  if (!k)
    printf("INF\n");
  else {
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = a[i]; j < maxm; j++)
        if (dp[j - a[i]] == 1) dp[j] = 1;

    for (int i = 1; i <= 20000; i++)
      if (dp[i] != 1) cnt += 1;

    printf("%d\n", cnt);
  }

  return 0;
}