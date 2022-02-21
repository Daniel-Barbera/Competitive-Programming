#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int horas, minutos;
    constexpr int maxMinutos = 60*24;
    while (scanf("%02d:%02d", &horas, &minutos) == 2 && (horas || minutos)) {
        minutos += horas*60;
        printf("%d\n", maxMinutos - minutos);
    }
    return 0;
}