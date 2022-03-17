#include <bits/stdc++.h>
using namespace std;

bitset<13000> sieve;
vector<int> primes;
void buildSieve() {
    sieve.set();
    for (int i = 2; i < sieve.size(); ++i) {
        if (sieve[i]) {
            for (int j = i*i; j < sieve.size(); j += i) {
                sieve[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int main() {
    int numCasos, num;
    string entrada;

    buildSieve();

    scanf("%d", &numCasos);
    cin.ignore();

    while(numCasos--) {
        num = 0;
        getline(cin, entrada);
        for (char c: entrada) {
            num += c;
        }
        auto it = lower_bound(primes.begin(), primes.end(), num) - 1;
        num = *it;
        printf("%d\n", num);
    }
}
