#include <iostream>
using namespace std;
/**
 * 标题：测试次数

x星球的居民脾气不太好，但好在他们生气的时候唯一的异常举动是：摔手机。
各大厂商也就纷纷推出各种耐摔型手机。x星球的质监局规定了手机必须经过耐摔测试，并且评定出一个耐摔指数来，之后才允许上市流通。

x星球有很多高耸入云的高塔，刚好可以用来做耐摔测试。塔的每一层高度都是一样的，与地球上稍有不同的是，他们的第一层不是地面，而是相当于我们的2楼。

如果手机从第7层扔下去没摔坏，但第8层摔坏了，则手机耐摔指数=7。
特别地，如果手机从第1层扔下去就坏了，则耐摔指数=0。
如果到了塔的最高层第n层扔没摔坏，则耐摔指数=n

为了减少测试次数，从每个厂家抽样3部手机参加测试。

某次测试的塔高为1000层，如果我们总是采用最佳策略，在最坏的运气下最多需要测试多少次才能确定手机的耐摔指数呢？

请填写这个最多测试次数。

注意：需要填写的是一个整数，不要填写任何多余内容。
*/

#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)

/**
 * The commonly used dynamic programming algorithm is adopted
 * para:
 *        n:numbers of floors.
 *        m:numbers of phones.
 * return:None
 */
void dynamic_programming(int n, int m) {
  int dp[1001][1001];
  //  layer by layer test
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp[i][j] = i;
  //  if it gets damaged at level i
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++)
      for (int k = 2; k < i; k++)
        dp[i][j] = min(max(dp[i - k][j] + 1, dp[k - 1][j - 1] + 1), dp[i][j]);
  // for (int cnt = 2; cnt <= m; cnt++)
  //   for (int ind = 1; ind <= n; ind++) {
  //     //  dp[1][2] = 1 + dp[0][2]
  //     //  dp[2][2] = 1 + (1 + dp[1][2])...
  //     dp[ind][cnt] = 1 + dp[ind - 1][cnt];

  //     for (int k = 2; k <= ind; k++)
  //       dp[ind][cnt] =
  //           Min(dp[ind][cnt], 1 + Max(dp[k - 1][cnt - 1], dp[ind - k][cnt]));
  //   }
  cout << dp[n][m] << "\n";
}

int main() {
  dynamic_programming(1000, 3);
  return 0;
}