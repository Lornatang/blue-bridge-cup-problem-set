#include <iostream>
using namespace std;

bool judge(int x, int y) {
  while (y > 0) {
    int tmp = x % y;
    x = y;
    y = tmp;
  }
  if (x == 1) return true;
  return false;
}