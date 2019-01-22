/**
 *
标题：日志统计

小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有N行。其中每一行的格式是：

ts id

表示在ts时刻编号id的帖子收到一个"赞"。

现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为D的时间段内收到不少于K个赞，小明就认为这个帖子曾是"热帖"。

具体来说，如果存在某个时刻T满足该帖在[T,
T+D)这段时间内(注意是左闭右开区间)收到不少于K个赞，该帖就曾是"热帖"。

给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。

【输入格式】
第一行包含三个整数N、D和K。
以下N行每行一条日志，包含两个整数ts和id。

对于50%的数据，1 <= K <= N <= 1000
对于100%的数据，1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000

【输出格式】
按从小到大的顺序输出热帖id。每个id一行。

【输入样例】
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3

【输出样例】
1
3


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

/**
 * n is the number of log rows。
 * d is the time to log.
 * k is tieba hot.
 */
int n, d, k;
vector<int> t[maxn];
int ans[maxn];

bool judge(int x) {
  int len = t[x].size();
  if (len < k) return 0;
  sort(t[x].begin(), t[x].end());

  int l = 0, r = 0, sum = 0;
  while (l <= r && r < len) {
    sum += 1;
    if (sum >= k) {
      if (t[x][r] - t[x][l] < d)  //注意是小于
        return 1;
      else
        l++, sum--;
    }
    r++;
  }

  return 0;
}

int main() {
  cin >> n >> d >> k;

  for (int i = 1; i <= n; i++) {
    int ts, id;
    cin >> ts >> id;
    t[id].push_back(ts);
  }

  int cnt = 0;
  for (int i = 1; i < maxn; i++)
    if (judge(i)) ans[++cnt] = i;

  for (int i = 1; i <= cnt; i++) cout << ans[i] << "\n";

  return 0;
}