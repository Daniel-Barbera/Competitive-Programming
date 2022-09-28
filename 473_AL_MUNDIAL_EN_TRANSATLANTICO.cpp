#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k, int m){
  int i;
  for (m = n - m, i = m + 1; i <= n; i++){
    m += k;
    if (m >= i) m %= i;
  }
  return m + 1;
}


int main() {
  ios_base::sync_with_stdio(false);
  int balls = 0, lost_each = 0;
  while (scanf("%d%d", &balls, &lost_each) && balls && lost_each) {
    printf("%d\n", josephus(balls, lost_each, balls));
  }
}