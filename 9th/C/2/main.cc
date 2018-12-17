/**
标题：明码

汉字的字形存在于字库中，即便在今天，16点阵的字库也仍然使用广泛。
16点阵的字库把每个汉字看成是16x16个像素信息。并把这些信息记录在字节中。

一个字节可以存储8位信息，用32个字节就可以存一个汉字的字形了。
把每个字节转为2进制表示，1表示墨迹，0表示底色。每行2个字节，
一共16行，布局是：

    第1字节，第2字节
    第3字节，第4字节
    ....
    第31字节, 第32字节

这道题目是给你一段多个汉字组成的信息，每个汉字用32个字节表示，这里给出了字节作为有符号整数的值。

题目的要求隐藏在这些信息中。你的任务是复原这些汉字的字形，从中看出题目的要求，并根据要求填写答案。

这段信息是（一共10个汉字）：
4 0 4 0 4 0 4 32 -1 -16 4 32 4 32 4 32 4 32 4 32 8 32 8 32 16 34 16 34 32 30 -64
0 16 64 16 64 34 68 127 126 66 -124 67 4 66 4 66 -124 126 100 66 36 66 4 66 4 66
4 126 4 66 40 0 16 4 0 4 0 4 0 4 32 -1 -16 4 32 4 32 4 32 4 32 4 32 8 32 8 32 16
34 16 34 32 30 -64 0 0 -128 64 -128 48 -128 17 8 1 -4 2 8 8 80 16 64 32 64 -32
64 32 -96 32 -96 33 16 34 8 36 14 40 4 4 0 3 0 1 0 0 4 -1 -2 4 0 4 16 7 -8 4 16
4 16 4 16 8 16 8 16 16 16 32 -96 64 64 16 64 20 72 62 -4 73 32 5 16 1 0 63 -8 1
0 -1 -2 0 64 0 80 63 -8 8 64 4 64 1 64 0 -128 0 16 63 -8 1 0 1 0 1 0 1 4 -1 -2 1
0 1 0 1 0 1 0 1 0 1 0 1 0 5 0 2 0 2 0 2 0 7 -16 8 32 24 64 37 -128 2 -128 12
-128 113 -4 2 8 12 16 18 32 33 -64 1 0 14 0 112 0 1 0 1 0 1 0 9 32 9 16 17 12 17
4 33 16 65 16 1 32 1 64 0 -128 1 0 2 0 12 0 112 0 0 0 0 0 7 -16 24 24 48 12 56
12 0 56 0 -32 0 -64 0 -128 0 0 0 0 1 -128 3 -64 1 -128 0 0


注意：需要提交的是一个整数，不要填写任何多余内容
*/

#include <math.h>
#include <iostream>
using namespace std;

int arr[8];
/**
 * 10 convert 2.
 * para:   value.
 * return: None.
 */
void exchange(int value) {
  int va = abs(value);
  // convert 2
  int i = 0;
  while (va != 0) {
    arr[i] = va % 2;
    va /= 2;
    i++;
  }
  //  Find the complement of a negative number
  if (value < 0)
    for (int i = 0; i <= 7; i++)
      if (arr[i] == 1 && i < 7) {
        for (int j = i + 1; j <= 7; j++)
          if (arr[j] == 0)
            arr[j] = 1;
          else
            arr[j] = 0;
        break;
      }
}

int main() {
  int a[32];
  //  Ten characters
  for (int e = 0; e <= 9; e++) {
    //  A number consists of 32 bytes
    for (int i = 0; i <= 31; i++) cin >> a[i];
    for (int i = 0; i <= 31; i++) {
      exchange(a[i]);
      for (int j = 7; j >= 0; j--)
        if (arr[j] == 1)
          cout << arr[j];
        else
          cout << " ";
      // Reset the array
      for (int z = 0; z <= 7; z++) arr[z] = 0;
      //  Line up every two bytes
      if (i % 2 == 1) cout << "\n";
    }
  }
  return 0;
}