#include <iostream>
using namespace std;

typedef long long ll;

ll bk[100010] = {0};
ll arr[1000010];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

  arr[0] %= k;
  ll sum = 0;

  for (int i = 1; i < n; i++) arr[i] = (arr[i] + arr[i - 1]) % k;

  for (int i = 0; i < n; i++) sum += (bk[arr[i]]++);

  printf("%lld\n", sum + bk[0]);
  return 0;
}
