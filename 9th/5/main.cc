/**
 * 标题：快速排序。

以下代码可以从数组a[]中找出第k小的元素。


它使用了类似快速排序中的分治算法，期望时间复杂度是O(N)的。


请仔细阅读分析源码，填写划线部分缺失的内容。
*/

#include <iostream>
using namespace std;

/**
 * look for the value that is smaller than value, which is the value of the \
 * sorted array.
 * para:  int arr[], int left, int right, int key.
 * return:quick_sort().
 */
int quick_select(int arr[], int l, int r, int k) {
  //  select a random number as the reference number
  //  p is positioned in the middle of the array
  int p = rand() % (r - l + 1) + l;
  //  swap arr[p], arr[r]
  int x = arr[p];
  {
    int t = arr[p];
    arr[p] = arr[r];
    arr[r] = t;
  }
  int i = l, j = r;
  while (i < j) {
    while (i < j && arr[i] < x) i++;
    if (i < j) {
      arr[j] = arr[i];
      j--;
    }
    while (i < j && arr[j] > x) j--;
    if (i < j) {
      arr[i] = arr[j];
      i++;
    }
  }
  arr[i] = x;
  p = i;
  if (i - l + 1 == k) return arr[i];
  if (i - l + 1 < k)
    return quick_select(arr, i + 1, r, k - (i - l + 1));  //填空
  else
    return quick_select(arr, l, i - 1, k);
}

/**
 * swap two values.
 * para:  *a, *b.
 * return: None.
 */
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * This code can write
 * look for the value that is smaller than value, which is the value of the\
 * sorted array.
 * para:
 *        arr[]: numbers of array.
 *        begin: array begin.
 *        end:   array end.
 *        index: array index.
 * return:None.
 */
void quick_sort(int arr[], int begin, int end, int index) {
  int i, j;
  if (begin < end) {
    i = begin + 1;
    j = end;
  }

  while (i < j) {
    if (arr[i] > arr[begin]) {
      swap(&arr[i], &arr[j]);
      j--;
    } else
      i++;
  }

  if (arr[i] >= arr[begin]) i--;

  swap(&arr[i], &arr[j]);
  quick_sort(arr, begin, i, index);
  quick_sort(arr, j, end, index);
}

int main() {
  int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
  cout << quick_select(a, 0, 14, 5) << "\n";
  return 0;
}