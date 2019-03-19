#include <iostream>
using namespace std;

int main(void) {
  string s1, s2;
  cin >> s1 >> s2;

  while (s1.size() > s2.size()) s2 = '0' + s2;
  while (s1.size() < s2.size()) s1 = '0' + s1;

  s1 = '0' + s1;
  s2 = '0' + s2;

  for (int i = s1.size() - 1; i >= 0; i--) {
    int num1 = s1[i] - '0';
    int num2 = s2[i] - '0';

    if (num1 + num2 > 9) {
      s1[i - 1] = s1[i - 1] - '0' + 1 + '0';
      s1[i] = (num1 + num2) - 10 + '0';
    } else
      s1[i] = (num1 + num2) + '0';
  }
  if (s1[0] == '0') s1.erase(0, 1);
  cout << s1 << "\n";

  return 0;
}
