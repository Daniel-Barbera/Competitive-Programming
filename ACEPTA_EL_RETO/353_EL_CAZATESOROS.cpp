#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct cofre {
    int profundidad, oro;
    cofre(){}
    cofre(int a, int b) {
        profundidad = a;
        oro = b;
    }
    bool operator== (cofre other) const {
        return other.profundidad == profundidad && other.oro == oro;
    }
};

vector<vector<int>> memo(105, vector<int>(10005, -1));  // [100][10000] <- [indiceCofre][tiempoTotal]
int maxTiempo, numCofres;
cofre cofres[105];  // <profundidad, oro>
set<int> sol; // soluciones se piden en orden de aparición (ordenar por índice)

// Knapsack
// BOTTOM UP
int valorMaximo(int index, int tiempo) {
    if (tiempo < 0 || index < 0) return -INF;    // <- Nodo inválido
    if (tiempo == 0) return 0;  // <- Fin rama
    // Memo
    if (memo[index][tiempo] != -1) return memo[index][tiempo];
    // Caso base
    if (index == 0) {
        if (tiempo - 3*cofres[index].profundidad  >= 0)
            return cofres[index].oro;
        return 0;
    }
    // Transición
    memo[index][tiempo] = max(
        valorMaximo(index-1, tiempo - 3*cofres[index].profundidad) + cofres[index].oro, // Cogemos el cofre
        valorMaximo(index-1, tiempo) // No lo cogemos
    );
    return memo[index][tiempo];
}

void print_DP(int index, int tiempo) {
    // Nodo inválido
    if (index < 0 || tiempo <= 0) return;
    // Caso base
    if (index == 0) {
        if (tiempo - 3*cofres[index].profundidad  >= 0)
            sol.insert(index);
        return;
    } // Transición
    if (valorMaximo(index-1, tiempo - 3*cofres[index].profundidad) + cofres[index].oro > valorMaximo(index-1, tiempo)) {
        sol.insert(index);
        print_DP(index-1, tiempo - 3*cofres[index].profundidad);
    } else print_DP(index - 1, tiempo);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> maxTiempo) {
        
        cin >> numCofres;
        for (int i = 0; i < numCofres; ++i) {
            cin >> cofres[i].profundidad >> cofres[i].oro;
        }

        cout << valorMaximo(numCofres - 1, maxTiempo) << '\n';
        print_DP(numCofres - 1, maxTiempo);
        cout << sol.size() << '\n';
        for (auto it: sol) cout << cofres[it].profundidad << ' ' << cofres[it].oro << '\n';
        cout << "----\n";

        // Limpiar variables
        for (int i = 0; i < numCofres; ++i) {
            for (int j = 0; j < 10005; ++j) {
                memo[i][j] = -1;
            }
        }
        sol.clear();
    }
}