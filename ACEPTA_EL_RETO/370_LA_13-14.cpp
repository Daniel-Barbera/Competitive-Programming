#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos, a, b;
    scanf("%d",&numCasos);
    while (numCasos--) {
        scanf("%d-%d", &a, &b);
        if (abs(a - b) != 1) {
            printf("NO\n");
            continue;
        }
        a = min(a, b);
        a % 2 == 0 ? printf("SI\n") : printf("NO\n");
    }
}