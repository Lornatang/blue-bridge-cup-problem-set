/**
 *
标题：等差素数列

2,3,5,7,11,13,....是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。

2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！

有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：

长度为10的等差素数列，其公差最小值是多少？

注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。
*/

#include <iostream>
using namespace std;
typedef long long ll;

bool check(ll n) {
  if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
  for (ll i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}

int main() {
  for (int d = 2; d < 1000; d++)
    for (ll n = 2; n < 1000; n++) {
      if (check(n) && check(n + 1 * d) && check(n + 2 * d) &&
          check(n + 3 * d) && check(n + 4 * d) && check(n + 5 * d) &&
          check(n + 6 * d) && check(n + 7 * d) && check(n + 8 * d) &&
          check(n + 9 * d)) {
        printf("%d\n", d);
        break;
      }
    }

  return 0;
}