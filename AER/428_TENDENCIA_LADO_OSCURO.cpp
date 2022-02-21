#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos;
    int num, cuatros;
    bool masDeUnCuatro;
    scanf("%d", &numCasos);
    while (numCasos--) {
        scanf("%d", &num);
        masDeUnCuatro = false;
        cuatros = 0;
        while (num != 0 && !masDeUnCuatro) {
            if (num % 5 == 4) ++cuatros;
            masDeUnCuatro = cuatros > 1;
            num /= 5;
        }
        masDeUnCuatro ? printf("SI\n") : printf("NO\n");
    }

    return 0;
}