#include <iostream>
using namespace std;

int main() {
  double line[60][60];
  double min_n, max_n;
  int i, j;

  // memset(line, 0, sizeof(line));

  freopen("dat.txt", "r", stdin);
  for (i = 1; i <= 29; i++)
    for (j = 1; j <= i; j++) cin >> line[i][j];

  for (i = 1; i <= 29; i++)
    for (j = 1; j <= i; j++) {
      line[i + 1][j] += line[i][j] / 2;
      line[i + 1][j + 1] += line[i][j] / 2;
    }

  max_n = min_n = line[30][1];

  for (i = 1; i <= 30; i++) {
    if (min_n < line[30][i]) min_n = line[30][i];
    if (max_n > line[30][i]) max_n = line[30][i];
  }

  printf("n=m== %lf %lf\n", min_n, max_n);

  printf("%lf\n", min_n * 2086458231 / max_n);

  return 0;
}