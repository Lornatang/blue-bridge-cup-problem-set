#include <iostream>
using namespace std;

string Sub(string a, string b) {
  while (a.size() > b.size()) b = '0' + b;
  while (a.size() < b.size()) a = '0' + a;

  if (b > a) {
    string temp = b;
    b = a;
    a = temp;
  }

  for (int i = a.size() - 1; i >= 0; i--) {
    int num1 = a[i] - '0';
    int num2 = b[i] - '0';
    if (num2 > num1) {
      a[i - 1] = a[i - 1] - '0' - 1 + '0';
      a[i] = (num1 + 10 - num2) + '0';
    } else
      a[i] = (num1 - num2) + '0';
  }

  if (a[0] == '0') a.erase(0, 1);
  return a;
}

int main(void) {
  string s1, s2;
  cin >> s1 >> s2;
  string res;
  res = Sub(s1, s2);
  cout << res << "\n";
  return 0;
}