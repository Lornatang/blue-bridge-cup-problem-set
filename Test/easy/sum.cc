#include <iostream>

#define ll long long

const int maxn = 1e9 + 10;

ll solve(ll n) { return n * (n + 1) / 2; }

int main(void) {
  ll n;
  scanf("%lld", &n);
  printf("%lld", solve(n));
  return 0;
}