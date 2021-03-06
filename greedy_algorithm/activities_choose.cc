/*
 * 活动选择问题：
 *
 * 调度竞争共享资源的多个活动的问题，目标是选出一个最大的互相兼容的活动集合。假定有一个n个活动的集合S={a1,a2,a3...,an}，
 * 这些活动使用同一个资源（例如同一个阶梯教室），而这个资源在某个时刻只能供一个活动使用。每个互动ai都有一个开始时间s和一个结束时间fi，
 * 其中)<=si<fi<无穷。如果被选中，任务ai发生在半开时间区[si,fi)期间。如果两个活动ai和aj满足[si,fi)和[sj,fj)不重叠，则称它们是兼容的。
 * 也就是说，若si>=fj，或sj>=fi，则ai和j是兼容的。在活动选择问题中，我们希望选出一个最大兼容活动集。假定活动已按照结束时间的单调递增
 * 排序
 *
 * 原本的思路：按照动态规划的方法来求，先求子问题：将Sij的一个最大兼容活动集合设为Aij，于是Aij至少包含一个活动ak，则：
 * 可以将Aij划分为子问题：Aij=Aik+ak+Akj
 *
 * 但是我们一开始不能知道哪一个k能够使得ak一定在最大兼容活动集Aij中，于是一般的需要从i~j便利所有的k的可能取值，来找这个ak。
 *
 * 上面是动态规划的思路；但是对于贪心算法而言，这里ak不去
 * 遍历，而只是去寻找第一个结束的活动，也就是a1。这里可以证明，a1一定是在
 * Sij的某一个最大兼容活动集Aij中。证明方法：
 *
 * 假设Aij是Sij的某个最大兼容活动集，假设Aij中，最早结束的活动是an，分两种情况：
 *
 * ①如果an=a1，则得证
 * ②如果an不等于a1，则an的结束时间一定会晚于a1的结束时间，我们用a1去替换Aij中的an，于是得到A`，由于a1比an结束的早，而Aij中的其他活动
 * 都比an的结束时间开始 的要晚，所以A`中的其他活动
 * 都与a1不想交，所以A`中的所有活动是兼容的，所以A`也是Sij的一个最大兼容活动集。
 *
 * 得证
 *
 * 于是我们下面使用贪心算法来做，分别用递归和迭代两个版本。
 */

#include <iostream>
#include <vector>
using namespace std;

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void quick_sort(int s[], int l, int r) {
  if (l < r) {
    int i = l, j = r, x = s[l];
    while (i < j) {
      // 从右向左找第一个小于x的数
      while (i < j && s[j] >= x) j--;
      if (i < j) swap(s[i++], s[j]);

      // 从左向右找第一个大于等于x的数
      while (i < j && s[i] < x) i++;
      if (i < j) swap(s[j--], s[i]);
    }
    s[i] = x;
    quick_sort(s, l, i - 1);  // 递归调用
    quick_sort(s, i + 1, r);
  }
}

void solve(vector<int> *A, int *a, int *b, int k, int n) {
  int m = k + 1;
  while (m <= n && a[m] < b[k]) m += 1;
  if (m <= n) {
    A->push_back(m);
    solve(A, a, b, m, n);
  }
}

int main(void) {
  int s[11] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};

  int f[11] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

  //先将f按从小到大排序，s的位置随f而动
  quick_sort(f, 0, 12 - 1);
  quick_sort(s, 0, 12 - 1);

  vector<int> *A = new vector<int>;

  solve(A, s, f, 0, 11 - 1);

  vector<int>::iterator iter;

  for (iter = A->begin(); iter != A->end(); iter++) printf("%d ", *iter);
  printf("\n");
  delete A;

  return 0;
}