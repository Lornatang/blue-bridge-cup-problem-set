#include <math.h>
#include <iostream>

int flag[3][4];  //表示哪些可以填数
int mpt[3][4];   //填数
bool visit[10];
int ans = 0;
void init()  //初始化
{
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 4; j++) flag[i][j] = 1;
  flag[0][0] = 0;
  flag[2][3] = 0;
}

void Solve() {
  int dir[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
  int book = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      //判断每个数周围是否满足
      if (flag[i][j] == 0) continue;
      for (int k = 0; k < 8; k++) {
        int x, y;
        x = i + dir[k][0];
        y = j + dir[k][1];
        if (x < 0 || x >= 3 || y < 0 || y >= 4 || flag[x][y] == 0) continue;
        if (abs(mpt[x][y] - mpt[i][j]) == 1) book = false;
      }
    }
  }
  if (book) ans++;
}

void dfs(int index) {
  int x, y;
  x = index / 4;
  y = index % 4;
  if (x == 3) {
    Solve();
    return;
  }
  if (flag[x][y]) {
    for (int i = 0; i < 10; i++) {
      if (!visit[i]) {
        visit[i] = true;
        mpt[x][y] = i;
        dfs(index + 1);
        visit[i] = false;
      }
    }
  } else {
    dfs(index + 1);
  }
}

int main() {
  init();
  dfs(0);
  printf("%d\n", ans);
  return 0;
}