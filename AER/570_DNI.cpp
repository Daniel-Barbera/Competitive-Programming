#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> ilegibles;
char caracteres[] = {
    'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'
};
string dni;
int calcularPosibles(int index) {
    if (index == ilegibles.size()) {
        if (caracteres[stoi(dni) % 23] == *dni.rbegin()) return 1;
        return 0;
    }
    int result = 0;
    for (int i = 0; i <= 9; ++i) {
        dni[ilegibles[index]] = i - '0';
        result += calcularPosibles(index + 1);
    }
    return result;
}

int main() {
    int numCasos;

    cin >> numCasos;
    cin.ignore();
    while (numCasos--) {
        getline(cin, dni);
        // Ubicar los indices de los '?'
        for (int i = 0; i < 8; ++i) {
            if (dni[i] == '?') {
                ilegibles.push_back(i);
            }
        }
        cout << calcularPosibles(0) << '\n';
        ilegibles.clear();
    }
    return 0;
}

/*
3
1234567?Z
012??567L
?87?54?2M
*/