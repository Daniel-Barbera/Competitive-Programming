#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos;
    cin >> numCasos;
    int a, b;
    while (numCasos--) {
        cin >> a >> b; 
        cout << floor(((double) a/(double) (a+b))*100) << '\n';
    } 

    return 0;
}