#include <iostream>
using namespace std;

typedef long long ll;

ll bk[100010] = {0};
ll arr[1000010];

int main() {
  /*
  前缀和
  */
  int sum[100001];  // sum[i] 前i个元素的和
  int num[100001];
  int cnt[100001];
  int n, k;
  ll ans = 0;
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0, sizeof(sum));
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    sum[i] = (sum[i - 1] + num[i]) % k;
    ans += cnt[sum[i]];
    cnt[sum[i]]++;
  }

  printf("%lld\n", ans + cnt[0]);
  return 0;
}
