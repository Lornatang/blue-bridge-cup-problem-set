/**
 * 标题：第几天
 * 2000年的1月1日，是那一年的第1天。
 * 那么，2000年的5月4日，是那一年的第几天？
 * 注意：需要提交的是一个整数，不要填写任何多余内容。
 */

#include <iostream>
using namespace std;

/**
 * cal day sum.
 * para:   None.
 * return: day sum.
 */
int cal() {
  int year, month, day;
  cout << "Please input year\n";
  cin >> year;
  cout << "Please input month\n";
  cin >> month;
  cout << "Please input day\n";
  cin >> day;
  // cal day sum
  int sum;

  switch (month) {
    case 1:
      sum = 0;
      break;
    case 2:
      sum = 31;
      break;
    case 3:
      sum = 59;
      break;
    case 4:
      sum = 90;
      break;
    case 5:
      sum = 120;
      break;
    case 6:
      sum = 151;
      break;
    case 7:
      sum = 181;
      break;
    case 8:
      sum = 212;
      break;
    case 9:
      sum = 242;
      break;
    case 10:
      sum = 273;
      break;
    case 11:
      sum = 304;
      break;
    case 12:
      sum = 334;
      break;
  }
  sum = sum + day;
  bool flag;
  // check year is leap?
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    flag = true;
  else
    flag = false;
  if (flag && month > 2) sum += 1;

  return sum;
}

int main(void) {
  int sum;
  sum = cal();
  cout << sum;
  cout << "\n";
  return 0;
}
