#include <bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int input, total;
    long long int mcd;
    while (cin >> input && input) {
        total = mcd = 0;
        total += input;
        mcd = gcd(input, input);
        while (cin >> input && input) {
            total += input;
            mcd = gcd(mcd, input);
        }
        cout << total/mcd << '\n';
    }
}