/**
 * 最简单的钱币找零问题：这个问题在我们的日常生活中很普遍。
 * 假设1元、2元、5元、10元、20元、50元、100元的纸币
 * 分别有2, 5, 0, 3, 4, 3, 4张。
 * 现在要用这些钱来支付K元，至少要用多少张纸币？
 * 用贪心算法的思想，很显然，每一步尽可能用面值大的纸币即可。
 * 在日常生活中我们自然而然也是这么做的。在程序中已经事先将Value按照从小到大的顺序排好。
 */

#include <iostream>

int money[7] = {1, 2, 5, 10, 20, 50, 100};
int num[7] = {2, 5, 0, 3, 4, 3, 4};

int ans[7];

int solve(int x) {
  if (x > 0) {
    for (int i = 6; i >= 0; i--) {
      ans[i] = std::min(num[i], x / money[i]);
      x = x - ans[i] * money[i];
    }
    return 0;
  } else
    return x;
}

int main(void) {
  int n;
  scanf("%d", &n);
  if (!solve(n)) {
    printf("100: %d\n", ans[6]);
    printf("50: %d\n", ans[5]);
    printf("20: %d\n", ans[4]);
    printf("10: %d\n", ans[3]);
    printf("5: %d\n", ans[2]);
    printf("2: %d\n", ans[1]);
    printf("1: %d\n", ans[0]);
  }
  return 0;
}