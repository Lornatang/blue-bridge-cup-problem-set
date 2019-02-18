#include <iostream>
using namespace std;

int len(int x) {
  if (x < 10) return 1;
  return len(x / 10) + 1;
}

int f(int x, int k) {
  if (len(x) - k == 0) return x % 10;
  return f(x / 10, k);
}

int main() {
  int x = 23574;
  cout << f(x, 3) << "\n";
  return 0;
}