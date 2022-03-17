#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;


int drawCircles(int radio, pii centro, pii pt);

int main() {
    int radio, ptx, pty;
    while (scanf("%d %d %d", &radio, &ptx, &pty) == 3) {
        printf("%d\n", drawCircles(radio, {0, 0}, {ptx, pty}));
    }
}

int drawCircles(int radio, pii centro, pii pt) {
    bool belongs = ((pt.first*pt.first - 2*pt.first*centro.first + centro.first*centro.first) + (pt.second*pt.second - 2*pt.second*centro.second + centro.second*centro.second)) <= (radio*radio);
    if (!belongs) return 0;
    if (radio == 1) {
        if (belongs) return 1;
        return 0;
    }
    radio /= 2;
    return  belongs + drawCircles(radio, {radio, 0}, pt) + drawCircles(radio, {-radio, 0}, pt) +
            drawCircles(radio, {0, radio}, pt) + drawCircles(radio, {0, -radio}, pt);
}