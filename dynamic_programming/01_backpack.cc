/**
 * 容量为10的背包，有5种物品，每种物品数量无限，
 * 其重量分别为5，4，3，2，1，
 * 其价值分别为1，2，3，4，5。
 * 实现背包内物品价值最大。
 */

#include <iostream>

// W: weight.
// V: money.
int solve(int n, int W[], int V[]) {
  int f[11] = {0};

  for (int i = 0; i < 5; i++)
    for (int j = W[i]; j <= n; j++) f[j] = std::max(f[j], f[j - W[i]] + V[i]);

  return f[n];
}

int main(void) {
  int W[5] = {5, 4, 3, 2, 1};
  int V[5] = {1, 2, 3, 4, 5};

  int money = solve(10, W, V);
  printf("%d\n", money);
  return 0;
}
