#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int n, num;
    long long minEffort, a, b;
    while (scanf("%d", &n) && n) {
        minEffort = a = b = 0;

        while (n--) {
            scanf("%d", &num);
            pq.push(num);
        }

        if (pq.size() > 1) {
            while (!pq.empty()) {
                a = pq.top(); pq.pop();
                b = pq.top(); pq.pop();
                minEffort += (a + b);
                if (!pq.empty()) pq.push(a + b);
            }
        } else while(!pq.empty()) pq.pop();
        
        printf("%lld\n", minEffort);
    }
}