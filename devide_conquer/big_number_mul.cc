#include <iostream>
#include <string>
using namespace std;

string BigNumMultiply(string s1, string s2) {
  int m = s1.size(), n = s2.size();

  string str(m + n, '0');

  for (int i = n - 1; i >= 0; --i) {
    int mulflag = 0, addflag = 0;
    for (int j = m - 1; j >= 0; --j) {
      int temp1 = (s2[i] - '0') * (s1[j] - '0') + mulflag;
      mulflag = temp1 / 10;
      temp1 = temp1 % 10;
      int temp2 = str[i + j + 1] - '0' + temp1 + addflag;
      str[i + j + 1] = temp2 % 10 + 48;
      addflag = temp2 / 10;
    }
    str[i] += mulflag + addflag;
  }
  if (str[0] == '0') str = str.substr(1, str.size());
  return str;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << BigNumMultiply(s1, s2) << endl;

  return 0;
}