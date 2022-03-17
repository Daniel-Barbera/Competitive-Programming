#include <bits/stdc++.h>
using namespace std;

int main() {
    string input, tiempo;
    char conj;
    while (cin >> input >> tiempo && tiempo != "T") {
        conj = input[input.size()-2];
        input.pop_back(); input.pop_back();
        switch (conj) {
            case 'a':
                switch(tiempo[0]) {
                    case 'A':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                        break;
                    case 'P':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                        break;
                    case 'F':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                }
                break;
            case 'e':
                switch(tiempo[0]) {
                    case 'A':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                        break;
                    case 'P':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                        break;
                    case 'F':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                }
                break;
            case 'i':
                switch(tiempo[0]) {
                    case 'A':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                        break;
                    case 'P':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                        break;
                    case 'F':
                        cout << "Yo " << input << "o\n";
                        cout << "Tu " << input << "as\n";
                        cout << "El " << input << "a\n";
                        cout << "Nosotros " << input << "amos\n";
                        cout << "Vosotros " << input << "ais\n";
                        cout << "Ellos " << input << "an\n";
                }
                break;
        }

    }

    return 0;
}