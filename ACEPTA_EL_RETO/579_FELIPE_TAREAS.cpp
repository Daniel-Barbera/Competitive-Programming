#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    typedef pair<int, int> tarea;
    /* La STL utiliza un operador '<' para hacer las comparaciones necesarias. */
    auto comp = [](tarea a, tarea b) {
        if (a.first == b.first) return (a.second > b.second);
        return (a.first < b.first);
    };
    priority_queue<tarea, vector<tarea>, decltype(comp)> cola(comp);

    int numCasos = 1;
    tarea task;
    while (cin >> numCasos && numCasos != 0) {
        for (int i = 0; i < numCasos; ++i) {
            cin >> task.first >> task.second;
            cola.push(task);
        }
        while (!cola.empty()) {
            task = cola.top();
            cout << task.first << " " << task.second << "\n";
            cola.pop();
        }
        cout << "---" << "\n";        
    }
}