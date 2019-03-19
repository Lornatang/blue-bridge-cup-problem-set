#include <iostream>
using namespace std;

string Add(string a, string b) {
  while (a.size() > b.size()) b = '0' + b;
  while (b.size() > a.size()) a = '0' + a;

  a = '0' + a;
  b = '0' + b;

  for (int i = a.size() - 1; i >= 0; i--) {
    int num1 = a[i] - '0';
    int num2 = b[i] - '0';

    if (num1 + num2 > 9) {
      a[i - 1] = a[i - 1] - '0' + 1 + '0';
      a[i] = (num1 + num2) - 10 + '0';
    } else
      a[i] = (num1 + num2) + '0';
  }

  if (a[0] == '0') a.erase(0, 1);

  return a;
}

int main(void) {
  string s1, s2;
  cin >> s1 >> s2;
  string res;
  res = Add(s1, s2);
  cout << res << "\n";
  return 0;
}