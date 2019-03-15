#include <stdio.h>

int main(void) {
  int start, end;
  for (start = 1; start < 50; start++)
    for (end = start; end < 50; end++) {
      int sum = 0;
      for (int i = start; i <= end; i++) sum += i;
      if (sum == 236) printf("%d to %d", start, end);
    }

  return 0;
}