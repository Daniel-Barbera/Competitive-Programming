#include <string>
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct Paciente {
    string nombre;
    int gravedad;
    int id;
    Paciente() {}
    Paciente(string n, int g, int i) {
        nombre = n;
        gravedad = g;
        id = i;
    }
    auto operator< (Paciente other) const {
        if (other.gravedad == gravedad) return other.id < id;
        return other.gravedad > gravedad;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numEventos;
    string evento;
    priority_queue<Paciente> pq;
    int id;

    while (cin >> numEventos && numEventos) {
        id = 0;
        cin.ignore();
        while (numEventos--) {
            getline(cin, evento);
            if (evento[0] == 'A') {
                cout << pq.top().nombre << '\n';
                pq.pop();
            }
            else {
                ++id;
                Paciente pac;
                istringstream entrada(evento);
                entrada.ignore();

                pac.id = id;
                entrada >> pac.nombre >> pac.gravedad;
                pq.push(pac);
            }
        }
        while (!pq.empty()) pq.pop();
        cout << "----\n";
    }
}