#include <iostream>
using namespace std;

int week_day(int year, int month, int day) {
  if (month == 1 || month == 2) {
    month += 12;
    year -= 1;
  }
  return (day + month * 2 + (month + 1) * 3 / 5 + year + year / 4 - year / 100 +
          year / 400) %
             7 +
         1;
}

int main() {
  int y, day, cnt = 0;
  y = 1998;

  for (int i = 1; i <= 12; ++i) {
    day = week_day(y, i, 13);
    if (day == 5) {
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
