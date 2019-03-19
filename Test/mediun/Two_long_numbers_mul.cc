#include <iostream>
using namespace std;
const int maxn = 50;

void multi(int a, int b, long long *res) {
  long long base = 10000000000;
  long long x1 = a % base;
  long long x2 = a / base;
  long long y1 = b % base;
  long long y2 = b / base;

  long long n1 = x1 * y1;
  long long n2 = x2 * y1;
  long long n3 = x1 * y2;
  long long n4 = x2 * y2;

  res[3] = n1 % base;
  res[2] = n1 / base + n2 % base + n3 % base;
  res[1] = n2 / base + n3 / base + n4 % base;
  res[0] = n4 / base;

  res[2] += res[3] / base;
  res[3] = res[3] % base;
  res[1] += res[2] / base;
  res[2] = res[2] % base;
  res[0] += res[1] / base;
  res[1] = res[1] % base;
}

int main() {
  //  fstream cin("a.txt");
  char s1[10], s2[10];
  long long res[4] = {0, 0, 0, 0};

  cin >> s1 >> s2;

  int a = atoi(s1);
  int b = atoi(s2);

  multi(a, b, res);
  if (a == 0 || b == 0) {
    cout << "0" << endl;
    return 0;
  }
  int i = 0;
  while (res[i] == 0) i++;
  for (i = 0; i < 4; i++) {
    cout << res[i];
  }

  return 0;
}
