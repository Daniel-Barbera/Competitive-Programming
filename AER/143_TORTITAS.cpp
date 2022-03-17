#include <bits/stdc++.h>
using namespace std;


// TBD

int main() {
    int tortita, numVueltas, pos;
    deque<int> tortitas, mitadSup, mitadInf;
    while (scanf("%d", &tortita) && tortita) {
        tortitas.clear(); mitadSup.clear(); mitadInf.clear();
        tortitas.push_front(tortita);
        while (scanf("%d", &tortita) && tortita != -1) {
            tortitas.push_back(tortita);
        }
        scanf("%d", &numVueltas);
    }

    return 0;
}