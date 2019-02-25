#include <iostream>
using namespace std;

typedef long long ll;
ll hi[100010];
ll wi[100010];
int n;
ll k;
bool isok(ll ans) {
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (hi[i] / ans) * (wi[i] / ans);
    if (sum >= k) return true;
  }
  return false;
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld%lld", &hi[i], &wi[i]);
  ll l = 1, r = 100000, ans;
  while (l <= r) {
    ans = (l + r) / 2;
    if (isok(ans))
      l = ans + 1;
    else
      r = ans - 1;
  }
  l++;
  while (l--) {
    if (isok(l)) break;
  }
  printf("%lld\n", l);
  return 0;
}