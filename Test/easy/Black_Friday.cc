#include <iostream>
using namespace std;

int cnt;

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
  int year;
  scanf("%d", &year);

  for (int month = 1; month <= 12; month++) {
    int day = week_day(year, month, 13);
    if (day == 5) {
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
