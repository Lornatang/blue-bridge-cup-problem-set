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
  int year1, year2;
  scanf("%d %d", &year1, &year2);

  for (int year = year1; year <= year2; year++) {
    int day = week_day(year, 10, 1);
    if (day == 7) {
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
