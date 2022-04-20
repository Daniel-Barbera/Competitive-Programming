#include <iostream>
#include <queue>
#include <deque>
#include <unordered_map>
using namespace std;

struct user {
    int id;
    int periodo;

    bool operator<(const user& b) const{
        if (periodo == b.periodo) return b.id < id;
        return b.periodo < periodo;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<user> cola;
    unordered_map<int, int> usuarios;
    user usuario;
    int numUsuarios;
    int envios;
    while (cin >> numUsuarios && numUsuarios) {
        while (numUsuarios--) {
            cin >> usuario.id >> usuario.periodo;
            usuarios[usuario.id] = usuario.periodo;
            cola.push(usuario);
        }
        cin >> envios;
        while (envios--) {
            usuario = cola.top(); cola.pop();
            cout << usuario.id << '\n';
            usuario.periodo = usuario.periodo + usuarios[usuario.id];
            cola.push(usuario);
        }
        while(!cola.empty()) cola.pop();
        cout << "----\n";
    }
    return 0;
}