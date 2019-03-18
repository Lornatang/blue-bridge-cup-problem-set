#include <iostream>
using namespace std;

const int maxm = 110;
const int maxt = 1010;
int dp[maxm][maxt] = {0};

int main(void) {
  int time, money;
  int t, v;
  scanf("%d %d", &time, &money);

  for (int i = 1; i <= money; i++) {
    scanf("%d %d", &t, &v);
    for (int j = 1; j <= time; j++) {
      if (j >= t)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + v);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  printf("%d\n", dp[money][time]);
  return 0;
}