#include <bits/stdc++.h>
using namespace std;

int main() {
    int numCasos, longSecuencia;
    long long int num;
    vector<long long int> secuencia;

    cin >> numCasos;
    while (numCasos--) {
        cin >> longSecuencia;
        for(int i = 0; i < longSecuencia; ++i) {
            cin >> num;
            secuencia.push_back(num);
        }

        sort(secuencia.begin(), secuencia.end(), greater<int>());

        long long int sumRed, sumBlue;
        int red, blue;
        sumRed = sumBlue = red = blue = 0;
        bool sePuede = false;

        auto itRed = secuencia.begin();
        if (longSecuencia % 2 != 0) {
            auto itBlue = secuencia.rbegin();
            while (itRed != secuencia.begin() + longSecuencia/2 && !sePuede&& red + blue <= longSecuencia) {
                sumRed += *itRed;
                ++red;
                ++itRed;
                for (int i = 0; i < 2 && itBlue != secuencia.rend(); ++i) {
                    sumBlue += *itBlue;
                    ++blue;
                    ++itBlue;
                }
                sePuede = sumRed > sumBlue && red + blue <= longSecuencia;
                if (itBlue == secuencia.rend()) break;
            }
        } else {
            auto itBlue = secuencia.rbegin();
            while (itRed != secuencia.begin() + longSecuencia/2 - 1 && !sePuede && red + blue <= longSecuencia) {
                sumRed += *itRed;
                ++red;
                ++itRed;
                for (int i = 0; i < 2 && itBlue != secuencia.rend(); ++i) {
                    sumBlue += *itBlue;
                    ++blue;
                    ++itBlue;
                }
                sePuede = sumRed > sumBlue && red + blue <= longSecuencia;
                if (itBlue == secuencia.rend()) break;
            }
        } 

        sePuede ? printf("yes\n") : printf("no\n");
        secuencia.clear();
    }
    return 0;
}