#include <stdio.h>

int main(void) {
  int a[101] = {0};
  int ans = 0;

  for (int i = 1; i < 101; i++) a[i] = a[i - 1] + i;

  for (int j = 1; j < 101; j++) ans += a[j];
  printf("%d\n", ans);

  return 0;
}