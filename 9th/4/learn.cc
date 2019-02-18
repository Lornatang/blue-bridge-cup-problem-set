/**
 * 扩展知识
 * 利用斐波那契数列来发现动态规划问题
 */

/*---------------------递归方法---------------------------------*/

#include <iostream>
using namespace std;

// /**
//  * 1, 1, 2, 3, 5, 8
//  */
// int fib(int n) {
//   if (n <= 0) return 0;
//   if (n == 1) return 1;
//   return fib(n - 1) + fib(n - 2);
// }

// // if input 6
// // then output 8
// int main() {
//   int a = fib(6);
//   cout << a << "\n";
// }

/*---------------------自顶向下备忘录方法---------------------------------*/

// /**
//  * 1, 1, 2, 3, 5, 8
//  */
// int fib(int n, int arr[]) {
//   //  if cal arr[n], return arr, eles cal arr[n+1]
//   if (arr[n] != -1) return arr[n];
//   if (n <= 2)
//     return arr[n] = 1;
//   else
//     return fib(n - 1, arr) + fib(n - 2, arr);
// }

// int main() {
//   int n = 6;
//   if (n <= 0) return n;
//   int arr[n + 1];
//   for (int i = 0; i <= n; i++) arr[i] = -1;
//   int a = fib(n, arr);
//   cout << a << endl;
// }

/*---------------------自底向上动态规划方法---------------------------------*/

/**
 * 1, 1, 2, 3, 5, 8
 * because index0, index1, index2 in trun increase 0, 1, 1
 * if n > 2 ,only cal index2 and index3...
 */
int fib(int n) {
  if (n <= 1) return n;
  int arr_i_2 = 0;  //  a = i - 2
  int arr_i_1 = 1;  //  b = i - 1
  int arr_i = 1;    //  c = i
  for (int i = 1; i < n; i++) {
    arr_i = arr_i_1 + arr_i_2;
    arr_i_2 = arr_i_1;
    arr_i_1 = arr_i;
  }
  return arr_i;
}

int main() {
  int a = fib(6);
  cout << a << endl;
}