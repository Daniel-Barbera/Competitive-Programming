#include <bits/stdc++.h>
using namespace std;

int main() {

    /* Cuatro casos que aclarar:

        CASO TRICKY #1:
        Como se puede observar en el enunciado:
            Tipos de rima:
            - Rima consonante: se dice que entre dos versos hay rima consonante cuando todos los sonidos,
            tanto vocales como consonantes, riman. Para las comparaciones se tienen
            en cuenta todos los sonidos a partir de la última vocal acentuada.
            - Rima asonante: similar a la anterior pero únicamente riman las vocales.
            
            También se define que:
            - Cuaderna via: rima CONSONANTE igual en todos los versos (AAAA)

            Caso de prueba #3:
            INPUT:
                4
                Era un simple clerigo, pobre de clerec[ia],
                dicie cutiano missa de la sancta Mar[ia];
                non sabie decir otra, diciela cada d[ia],
                mas la sabie por uso qe por sabidur[ia].
            OUTPUT: CUADERNA VIA
            CONCLUSIÓN: Si la rima contiene únicamente vocales, se considera CONSONANTE y no ASONANTE.

        CASO TRICKY #2:
            NO SE ESPECIFICA EL # DE VERSOS QUE UNA ESTROFA PUEDE TENER.
            Existen casos de prueba con 1 verso o más de 4 versos (testado).
            ¿Qué se debe hacer en estos casos? Dios lo sabe.

        CASO TRICKY #3:
            Cualquier cosa que pueda ser seguidilla, aparentemente.

        CASO TRICKY #4:
            Los casos de prueba proveídos no tienen NADA que ver con
            los que se emplean en el juez. Prepárate para tener:
                - Palabras que no estén separadas por espacios (?)
                - Versos con mayúsculas, por la cara.
                - Más de un símbolo raro al final de la última palabra (en los enunciados
                sólo se muestra un punto, una coma, pero pueden ser más de uno)
    */
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numLineas, posUltimaPalabra;
    vector<pair<string, bool>> rimas;   
    string verso;

    while (cin >> numLineas && numLineas) {
        cin.ignore();   // quitar '\n' restante después del entero

        // #2: No se especifica el # de versos
        if (numLineas == 1 || numLineas > 4 && (numLineas % 4 != 0 && numLineas % 3 != 0)) {
            while (numLineas--) getline(cin, verso);
            cout << "DESCONOCIDO\n";
            continue;
        } 

        for (int i = 0; i < numLineas; ++i) {
            // Capturar y procesar la última palabra de cada verso
            getline(cin, verso);
                // #4: Sanear input
            transform(verso.begin(), verso.end(), verso.begin(), [](unsigned char c){return tolower(c);});
            posUltimaPalabra = 0;
            if (verso.find_last_of(' ') != verso.npos) posUltimaPalabra = 1 + verso.find_last_of(' ');
            verso = verso.substr(posUltimaPalabra);
            int aux = 0;
            while (!isalpha(verso.back())) verso.pop_back();
            
            // Capturar rima
            string rima = ""; int numVocales = 0;
            bool hayConsonante = false;
            for (auto it = verso.rbegin(); it != verso.rend() && numVocales != 2; ++it) {
                if (!isalpha(*it)) break;
                if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u') ++numVocales;
                else hayConsonante = true;
                rima += *it;
            }
            // DEBUG FLAG: Si no hay vocales, no va a rimar.
            if (numVocales == 0) while (true) cout << "gracias aer\n";
            rimas.push_back({rima, hayConsonante});
        }

        // Resultado
        if (numLineas == 2) rimas[0] == rimas[1] ? cout << "PAREADO\n" : cout << "DESCONOCIDO\n";
        else {
            if (numLineas % 3 == 0 && numLineas % 4 != 0) {
                bool ter = true;
                for (int i = 0; i < rimas.size() && ter; i += 3) {
                    ter = rimas[i] == rimas[i+2] && rimas[i] != rimas[i+1];
                }
                ter ? cout << "TERCETO\n" : cout << "DESCONOCIDO\n";
            } else if (numLineas % 3 != 0 && numLineas % 4 == 0) {
                bool cVia, cto, cta, seg;
                cVia = cto = cta = seg = true;
                for (int i = 0; i < rimas.size(); i += 4) {
                    if (rimas[i] != rimas[i+1] || rimas[i] != rimas[i+2] || rimas[i] != rimas[i+3]) cVia = false;
                    if (rimas[i] != rimas[i+3] || rimas[i+1] != rimas[i+2]) cto = false;
                    if (rimas[i] != rimas[i+2] || rimas[i+1] != rimas[i+3]) cta = false;
                    if (seg) {
                        string vocalesVerso1, vocalesVerso2, vocalesVerso3, vocalesVerso4;
                        vocalesVerso1 = vocalesVerso2 = vocalesVerso3 = vocalesVerso4 = "";
                        /* Ojo con la seguidilla:
                            - No se considera seguidilla si cualquiera de los otros versos rima
                            - No se considera seguidilla si la rima de los versos 2 y 4 es consonante
                        */
                        for (auto it: rimas[i].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso1.push_back(it);
                            }
                        } 
                        for (auto it: rimas[i+1].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso2.push_back(it);
                            }
                        } 
                        for (auto it: rimas[i+2].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso3.push_back(it);
                            }
                        } 
                        for (auto it: rimas[i+3].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso4.push_back(it);
                            }
                        }
                        // Si la rima tiene consonantes, no pueden coincidir.
                        if (rimas[i+1].second && rimas[i+3].second && rimas[i+1].first == rimas[i+3].first) seg = false;
                        // Si la rima NO tiene consonantes, no pueden ser iguales.
                        if (!rimas[i+1].second && !rimas[i+3].second && rimas[i+1] == rimas[i+3]) seg = false;
                        // La rima no puede ser asonante en los versos 1 o 3.  
                        seg = seg && vocalesVerso2 == vocalesVerso4 && vocalesVerso1 != vocalesVerso2 && vocalesVerso3 != vocalesVerso2;
                    }
                }
                if (cVia || cto || cta || seg) {
                    if (cVia) cout << "CUADERNA VIA\n";
                    else if (cto) cout << "CUARTETO\n";
                    else if (cta) cout << "CUARTETA\n";
                    else if (seg) cout << "SEGUIDILLA\n";
                } else cout << "DESCONOCIDO\n";
            } else /*multiplo de 3 y 4*/ {
                bool cVia, cto, cta, seg;
                cVia = cto = cta = seg = true;
                for (int i = 0; i < rimas.size(); i += 4) {
                    if (rimas[i] != rimas[i+1] || rimas[i] != rimas[i+2] || rimas[i] != rimas[i+3]) cVia = false;
                    if (rimas[i] != rimas[i+3] || rimas[i+1] != rimas[i+2]) cto = false;
                    if (rimas[i] != rimas[i+2] || rimas[i+1] != rimas[i+3]) cta = false;
                    if (seg) {
                        string vocalesVerso1, vocalesVerso2, vocalesVerso3, vocalesVerso4;
                        vocalesVerso1 = vocalesVerso2 = vocalesVerso3 = vocalesVerso4 = "";
                        for (auto it: rimas[i].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso1.push_back(it);
                            }
                        } 
                        for (auto it: rimas[i+1].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso2.push_back(it);
                            }
                        } 
                        for (auto it: rimas[i+2].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso3.push_back(it);
                            }
                        } 
                        for (auto it: rimas[i+3].first) {
                            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                                vocalesVerso4.push_back(it);
                            }
                        }
                        // Si la rima tiene consonantes, no pueden coincidir. (Debe ser rima asonante)
                        if (rimas[i+1].second && rimas[i+3].second && rimas[i+1].first == rimas[i+3].first) seg = false;
                        // Si la rima NO tiene consonantes, no pueden ser iguales. (Rimas que solo contienen vocales se consideran consonantes)
                        if (!rimas[i+1].second && !rimas[i+3].second && rimas[i+1] == rimas[i+3]) seg = false;
                        // La rima no puede ser asonante en los versos 1 o 3.  
                        seg = seg && vocalesVerso2 == vocalesVerso4 && vocalesVerso1 != vocalesVerso2 && vocalesVerso3 != vocalesVerso2;
                    }
                }
                bool ter = true;
                for (int i = 0; i < rimas.size() && ter; i += 3) {
                    ter = rimas[i] == rimas[i+2] && rimas[i] != rimas[i+1];
                }
                if (ter) cout << "TERCETO\n";
                else if (cVia || cto || cta || seg) {
                    if (cVia) cout << "CUADERNA VIA\n";
                    else if (cto) cout << "CUARTETO\n";
                    else if (cta) cout << "CUARTETA\n";
                    else if (seg) cout << "SEGUIDILLA\n";
                } else cout << "DESCONOCIDO\n";
            }
        }
        rimas.clear();
    }
}