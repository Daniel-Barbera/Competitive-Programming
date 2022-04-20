#include <bits/stdc++.h>
using namespace std;
 
int calcEventosSimultaneos(vector<int> inicio, vector<int> fin) {
    sort(inicio.begin(), inicio.end());
    sort(fin.begin(), fin.end());

    int eventosSimultaneos = 1, maxSimultaneos = 1;
    int i = 1, j = 0;

    while (i < inicio.size() && j < fin.size()) {
        if (inicio[i] < fin[j]) {
        eventosSimultaneos++;
        maxSimultaneos = max(eventosSimultaneos, maxSimultaneos);
        i++;
        }
        else {
            eventosSimultaneos--;
            j++;
        }
    }
    return maxSimultaneos - 1; // <- necesitas n-1 compañeros porque tú tambien vas!
}
 
int main() {
    int numCasos, inic, fin;
    vector<int> mInicio, mFin;
    while(scanf("%d", &numCasos) == 1) {
        while (numCasos--) {
            scanf("%d %d", &inic, &fin);
            mInicio.push_back(inic);
            mFin.push_back(fin);
        }
        printf("%d\n", calcEventosSimultaneos(mInicio, mFin));
        mInicio.clear(); mFin.clear();
    }
    return 0;
}