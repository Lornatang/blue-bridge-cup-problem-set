#include <iostream>
using namespace std;

int main() {
  string hex[10];
  string bin[10];
  string oct[10];

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cin >> hex[i];

  // Hex to Bin
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < hex[i].length(); j++) {
      switch (hex[i][j]) {
        case '0':
          bin[i] += "0000";
          break;
        case '1':
          bin[i] += "0001";
          break;
        case '2':
          bin[i] += "0010";
          break;
        case '3':
          bin[i] += "0011";
          break;
        case '4':
          bin[i] += "0100";
          break;
        case '5':
          bin[i] += "0101";
          break;
        case '6':
          bin[i] += "0110";
          break;
        case '7':
          bin[i] += "0111";
          break;
        case '8':
          bin[i] += "1000";
          break;
        case '9':
          bin[i] += "1001";
          break;
        case 'A':
          bin[i] += "1010";
          break;
        case 'B':
          bin[i] += "1011";
          break;
        case 'C':
          bin[i] += "1100";
          break;
        case 'D':
          bin[i] += "1101";
          break;
        case 'E':
          bin[i] += "1110";
          break;
        case 'F':
          bin[i] += "1111";
          break;
        default:
          break;
      }
    }
  }
  // 2进制转8进制
  for (int i = 0; i < n; i++) {
    int len = bin[i].length();
    int num = 0;
    int temp = 3;
    for (int j = len - 1; j >= 0; j--) {
      if (bin[i][j] == '1') {
        switch (temp) {
          case 3:
            num += 1;
            break;
          case 2:
            num += 2;
            break;
          case 1:
            num += 4;
            break;
          default:
            break;
        }
      }
      temp--;
      if (temp == 0) {
        oct[i] += num + '0';
        num = 0;
        temp = 3;
      }
    }
    if (temp != 0) {
      oct[i] += num + '0';
    }
  }
  //对8进制数逆序
  for (int i = 0; i < n; i++) {
    char temp;
    int len = oct[i].length();
    for (int j = 0; j < len / 2; j++) {
      temp = oct[i][j];
      oct[i][j] = oct[i][len - 1 - j];
      oct[i][len - 1 - j] = temp;
    }
  }
  //输出数据
  for (int i = 0; i < n; i++) {
    int len = oct[i].length();
    int j = 0;
    while (oct[i][j++] == '0')
      ;
    for (--j; j < len; j++) {
      cout << oct[i][j];
    }
    cout << endl;
  }
  return 0;
}