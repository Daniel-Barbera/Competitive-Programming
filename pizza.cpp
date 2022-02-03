#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
    return 0;
}

set<string> ingredientesPizza;
set<string> noGustan;

void procesarEntrada(string entrada) {
    string noGustan = entrada.pillarNoGustan();
    string gustan = entrada.pillarGustan();
    Cliente cl = new Cliente(gustan, noGustan);

    
}