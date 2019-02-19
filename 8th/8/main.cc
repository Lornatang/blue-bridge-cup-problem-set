#include <iostream>
using namespace std;

bool judge(int x, int y) {
  while (y > 0) {
    int tmp = x % y;
    x = y;
    y = tmp;
  }
  if (x == 1) return true;
  return false;
}

int a[110], n;
bool dp[10110];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      if (judge(a[i], a[j])) {
        flag = true;
        break;
      }
    }
    if (flag == 1) break;
  }

  if (flag != 1) {
    cout << "INF\n";
    return 0;
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + a[i] < 10000; j++)
      if (dp[j]) dp[j + a[i]] = 1;
  }
  int ans = 0;
  for (int i = 0; i < 10000; i++) {
    if (dp[i] != 1) ans++;
  }
  cout << ans << "\n";
  return 0;
}