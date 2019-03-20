/**
 * 容量为10的背包，有5种物品，
 * 每种物品数量分别为1，2，1，2，1，
 * 其重量分别为5，4，3，2，1，
 * 其价值分别为1，2，3，4，5。
 * 设计算法，实现背包内物品价值最大。
 */

#include <iostream>

int solve(int n, int cnt[], int w[], int v[]) {
  int f[11] = {0};

  for (int i = 0; i < 5; i++)
    for (int k = 1; k <= cnt[i]; k++)
      for (int j = w[i]; j <= n; j++) f[j] = std::max(f[j], f[j - w[i]] + v[i]);
  return f[n];
}

int main(void) {
  int cnt[] = {1, 2, 1, 2, 1};
  int W[] = {5, 4, 3, 2, 1};
  int V[] = {1, 2, 3, 4, 5};

  int money = solve(10, cnt, W, V);
  printf("%d\n", money);

  return 0;
}