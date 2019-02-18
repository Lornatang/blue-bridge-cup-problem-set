/**
 *
标题： 购物单

    小明刚刚找到工作，老板人很好，只是老板夫人很爱购物。老板忙的时候经常让小明帮忙到商场代为购物。小明很厌烦，但又不好推辞。

    这不，XX大促销又来了！老板夫人开出了长长的购物单，都是有打优惠的。
    小明也有个怪癖，不到万不得已，从不刷卡，直接现金搞定。
    现在小明很心烦，请你帮他计算一下，需要从取款机上取多少现金，才能搞定这次购物。

    取款机只能提供100元面额的纸币。小明想尽可能少取些现金，够用就行了。
    你的任务是计算出，小明最少需要取多少现金。

以下是让人头疼的购物单，为了保护隐私，物品名称被隐藏了。
-----------------
****.     180.90       80
****.      10.25       65
****.      56.14        90
****.     104.65        90
****.     100.30       88
****.     297.15        50
****.      26.75       65
****.     130.62        50
****.     240.28       58
****.     270.62        80
****.     115.87       88
****.     247.34       95
****.      73.21       90
****.     101.00        50
****.      79.54        50
****.     278.44        70
****.     199.26        50
****.      12.97        90
****.     166.30       78
****.     125.50       58
****.      84.98        90
****.     113.35       68
****.     166.57        50
****.      42.56        90
****.      81.90       95
****.     131.78        80
****.     255.89       78
****.     109.17        90
****.     146.69       68
****.     139.33       65
****.     141.16       78
****.     154.74        80
****.      59.42        80
****.      85.44       68
****.     293.70       88
****.     261.79       65
****.      11.30       88
****.     268.27       58
****.     128.29       88
****.     251.03        80
****.     208.39       75
****.     128.88       75
****.      62.06        90
****.     225.87       75
****.      12.89       75
****.      34.28       75
****.      62.16       58
****.     129.12       50
****.     218.37       50
****.     289.69        80
--------------------

需要说明的是，88指的是按标价的88%计算，而8是按80%计算，余者类推。
特别地，半价是按50%计算。

请提交小明要从取款机上提取的金额，单位是元。
答案是一个整数，类似4300的样子，结尾必然是00，不要填写任何多余的内容。


特别提醒：不许携带计算器入场，也不能打开手机。
*/

#include <iostream>
using namespace std;

int main() {
  freopen("dat.txt", "r", stdin);
  float ans = 0, a;
  int b;
  char buf[1000];
  while (scanf("%s%f%d", buf, &a, &b) != EOF) {
    ans += a * b / 100;
  }
  cout << ans << "\n";
  return 0;
}