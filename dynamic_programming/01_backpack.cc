/**
 * 容量为10的背包，有5种物品，每种物品数量无限，
 * 其重量分别为5，4，3，2，1，
 * 其价值分别为1，2，3，4，5。
 * 实现背包内物品价值最大。
 */

#include <iostream>
#include <vector>
using namespace std;

// W: weight.
// V: money.
int solve(int n, vector<int> W, vector<int> V) {
  int k = W.size();
  vector<int> f(n + 1, 0);

  for (int i = 0; i < W.size(); i++)
    for (int j = W[i]; j <= n; j++) f[j] = max(f[j], f[j - W[i]] + V[i]);

  return f[n];
}

int main(void) {
  int w[] = {5, 4, 3, 2, 1};
  int v[] = {1, 2, 3, 4, 5};
  vector<int> W(w, w + 5);
  vector<int> V(v, v + 5);

  int money = solve(10, W, V);
  printf("%d\n", money);
  return 0;
}
