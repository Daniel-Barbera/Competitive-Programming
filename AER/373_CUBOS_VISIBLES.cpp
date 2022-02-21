#include <bits/stdc++.h>
using namespace std;



int main() {
    /* Este problema es mucho más fácil de resolver si se resuelve
    para una única capa, y se multiplica ese resultado por el número
    de capas del cubo. A este resultado se le suma las "tapas" superior
    e inferior del cubo.*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int numCasos;
    unsigned long long int n;
    unsigned long long int res;
    cin >> numCasos;
    while (numCasos--) {
        cin >> n;
        res = 4*(n-1)*n + 2*((n-2)*(n-2));
        cout << res << '\n';
    }
    return 0;
}