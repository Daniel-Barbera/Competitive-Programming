#include <bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    int numCasos = 1;
    int nums[5];
    int resultado;
    while (cin >> numCasos && numCasos != 0) {
        for (int i = 0; i < numCasos; ++i) {
            cin >> nums[i];
        }
        resultado = nums[0];
        for (int i = 1; i < numCasos; ++i) {
            resultado = lcm(resultado, nums[i]);
        }
        cout << resultado << "\n";
    }
    return 0;
}