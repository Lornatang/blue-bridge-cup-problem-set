#include <iostream>
using namespace std;

int date[150][15][35];

bool checkIsLeapYear(int year, int month, int day) {
  bool flag = false;
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
      month == 10 || month == 12)
    if (day > 31) return 0;
  if (month == 4 || month == 6 || month == 9 || month == 11)
    if (day > 30) return 0;
  if (month == 2)
    if (day > 28 && !flag) return 0;
  return true;
}

int main() {
  int year, month, day;
  scanf("%d/%d/%d", &year, &month, &day);
  if (year >= 60 && month <= 12 && day <= 31) date[year - 60][month][day] = 1;
  if (year < 60 && month <= 12 && day <= 31) date[year + 40][month][day] = 1;
  if (year >= 60 && day <= 12 && month <= 31) date[year - 60][day][month] = 1;
  if (year < 60 && day <= 12 && month <= 31) date[year + 40][day][month] = 1;

  if (month >= 60 && year <= 12 && day <= 31) date[month - 60][year][day] = 1;
  if (month < 60 && year <= 12 && day <= 31) date[month + 40][year][day] = 1;
  if (month >= 60 && day <= 12 && year <= 31) date[month - 60][day][year] = 1;
  if (month < 60 && day <= 12 && year <= 31) date[month + 40][day][year] = 1;

  if (day >= 60 && month <= 12 && year <= 31) date[day - 60][month][year] = 1;
  if (day < 60 && month <= 12 && year <= 31) date[day + 40][month][year] = 1;
  if (day >= 60 && year <= 12 && month <= 31) date[day - 60][year][month] = 1;
  if (day < 60 && year <= 12 && month <= 31) date[day + 40][year][month] = 1;

  for (int i = 0; i <= 100; i++)
    for (int j = 1; j <= 12; j++)
      for (int k = 1; k <= 31; k++)
        if (date[i][j][k] == 1) {
          if (checkIsLeapYear(i, j, k)) {
            printf("%d-", i + 1960);
            if (j < 9)
              printf("0%d-", j);
            else
              printf("%d-", j);
            if (k < 9)
              printf("0%d\n", k);
            else
              printf("%d\n", k);
          }
        }
  return 0;
}
