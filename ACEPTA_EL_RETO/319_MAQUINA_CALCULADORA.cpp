#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;


bool visited[10050];

/* Lógica del BFS:
    Cada nodo del árbol de soluciones es resultante de operar sobre el nodo anterior
    Se llevará la cuenta de cuántos nodos hemos atravesado insertando dicho número en la cola
    (cur.second);
*/


int bfs(int a, int b) {
    queue<pii> q;
    q.push({a, 0});
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        if (cur.first == b) return cur.second;
        int sum = (cur.first+1+10000)%10000;
        if(visited[sum]==0) {
            visited[sum]= 1;
            q.push({sum,cur.second+1});
        }
        int mul = (cur.first*2+10000)%10000;
        if(visited[mul]==0) {
            visited[mul]= 1;
            q.push({mul,cur.second+1});
        }
        int div = cur.first/3;
        if(visited[div]==0) {
            visited[div] = 1;
            q.push({(cur.first/3),cur.second+1});
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    while (cin >> a >> b) {
        memset(visited, 0, sizeof(visited));
        cout << bfs(a, b) << '\n';
    }
}