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

#include <iostream>
using namespace std;

#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)

void dynamic_programming() {
  int dp[1000][3];
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    dp[i][1] = i;
  }
  for (int cnt = 2; cnt <= m; cnt++) {
    for (int ind = 1; ind <= n; ind++) {
      dp[ind][cnt] = 1 + dp[ind - 1][cnt];
      for (int k = 2; k <= ind; k++)
        dp[ind][cnt] =
            Min(dp[ind][cnt], 1 + Max(dp[k - 1][cnt - 1], dp[ind - k][cnt]));
    }
  }
  printf("%d\n", dp[n][m]);
}

int main() {
  dynamic_programming();
  return 0;
}