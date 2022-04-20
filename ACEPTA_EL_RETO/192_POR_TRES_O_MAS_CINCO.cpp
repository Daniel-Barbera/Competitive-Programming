#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bool visited[20050];
    fill(visited, visited + 20050, false);
    int num;

    queue<int> cola;
    cola.push(1);
    visited[1] = true;
    while (!cola.empty()) {
        num = cola.front(); cola.pop();
        int porTres = num * 3;
        int masCinco = num + 5;

        if (porTres <= 20000 && !visited[porTres]) {
            cola.push(porTres);
            visited[porTres] = true;
        }
        if (masCinco <= 20000 && !visited[masCinco]) {
            cola.push(masCinco);
            visited[masCinco] = true;
        }

    }

    while (cin >> num && num) {
        visited[num] ? cout << "SI\n" : cout << "NO\n";
    }
    return 0;
}