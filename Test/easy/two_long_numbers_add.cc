/**
 *
#include <iostream>

#define MAX 1000

void InputNumber(char *num_1, char *num_2) {
  char temp[MAX];

  memset(temp, 0, sizeof(temp));
  scanf("%s", temp);

  for (int i = num_1[0] = strlen(temp); i > 0; i--)
    num_1[i] = temp[num_1[0] - i] - '0';  //逆序并转换成相应的数字

  memset(temp, 0, sizeof(temp));
  scanf("%s", temp);

  for (int i = num_2[0] = strlen(temp); i > 0; i--)
    num_2[i] = temp[num_2[0] - i] - '0';  //逆序并转换成相应的数字
}
void AddNumber(char *num_1, char *num_2, char *sum) {
  sum[0] = std::max(num_1[0], num_2[0]);
  for (int i = 1; i <= sum[0]; i++)  //相加至长度最大的那个才结束
  {
    sum[i] += num_1[i] + num_2[i];  //计算相加
    sum[i + 1] = sum[i] / 10;       //把进位的数值留到下一位
    sum[i] %= 10;
  }
}
void OutputNumber(char *sum) {
  for (int i = ++sum[0]; !sum[i] && 1 < i; sum[0]--, i--)
    ;
  //长度增加1，比如99+1==100，就是3位长度；过滤前导0；避免结果全部是0，所以只留下一位不过滤

  for (int i = sum[0]; i > 0; i--) printf("%d", (int)sum[i]);

  printf("\n");
}

int main(void) {
  char num_1[MAX], num_2[MAX], num_3[MAX];
  memset(num_1, 0, sizeof(num_1));  // 存放加数，并清空
  memset(num_2, 0, sizeof(num_2));  // 存放加数，并清空
  memset(num_3, 0, sizeof(num_3));  // 存放结果，并清空
  InputNumber(num_1, num_2);        // 输入2个加数
  AddNumber(num_1, num_2, num_3);   // 计算相加
  OutputNumber(num_3);              // 输出结果

  return 0;
}
*/