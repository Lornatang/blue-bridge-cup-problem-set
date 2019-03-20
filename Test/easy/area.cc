#include <math.h>
#include <iostream>

#define ll long long
#define PI 3.14159265358979323;
const int maxn = 1e4 + 10;

double solve(ll n) { return n * n * PI; }

int main(void) {
  ll n;
  scanf("%lld", &n);
  printf("%.7f\n", solve(n));
  return 0;
}