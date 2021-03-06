/**
 *
标题：递增三元组

给定三个整数数组
A = [A1, A2, ... AN],
B = [B1, B2, ... BN],
C = [C1, C2, ... CN]，
请你统计有多少个三元组(i, j, k) 满足：
1. 1 <= i, j, k <= N
2. Ai < Bj < Ck

【输入格式】
第一行包含一个整数N。
第二行包含N个整数A1, A2, ... AN。
第三行包含N个整数B1, B2, ... BN。
第四行包含N个整数C1, C2, ... CN。

对于30%的数据，1 <= N <= 100
对于60%的数据，1 <= N <= 1000
对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000

【输出格式】
一个整数表示答案

【样例输入】
3
1 1 1
2 2 2
3 3 3

【样例输出】
27


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
using namespace std;

int func() {
  /**
   * define array max length
   * 对于30%的数据，1 <= N <= 100
   * 对于60%的数据，1 <= N <= 1000
   * 对于100%的数据，1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000
   * para:  None.
   * return:sum
   */
  const int MAXLEN = 100001;
  int a[MAXLEN], b[MAXLEN], c[MAXLEN];
  // b[MAXLEN], c[MAXLEN];
  //  define array length
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(a, a + n);
  sort(b, b + n);
  sort(c, c + n);
  //  old code
  // for (int i = 0; i < n; i++) {
  //   int x = (lower_bound(a, a + n, b[i]) - a);
  //   cout << x << endl;
  //   int y = (n - (upper_bound(c, c + n, b[i]) - c));
  //   cout << y << endl;
  //   sum += x * y;
  // }
  //  new code
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (a[j] < b[j]) sum += 1;
      if (b[j] < c[j]) sum += 1;
      if (a[j] < c[j]) sum += 1;
    }

  return sum;
}
int main() {
  int sum = func();
  cout << sum << "\n";
  return 0;
}