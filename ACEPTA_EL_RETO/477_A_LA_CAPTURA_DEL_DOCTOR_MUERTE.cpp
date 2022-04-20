#include <bits/stdc++.h>
using namespace std;

struct weapon {
    int inn, vill; 
    weapon(){}
    weapon(int i, int v) {
        inn = i;
        vill = v;
    }
    bool operator< (weapon& other) const {
        if (other.inn == inn) {
            return other.vill < vill;
        } else return other.inn < inn;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int hp, weapons, required; 
    weapon wep; 
    priority_queue<weapon> pq; 
    while (scanf("%d %d", &hp, &weapons) == 2) {
        while (weapons--) {
            scanf("%d %d", &wep.inn, &wep.vill);
            pq.push(wep);
        }
        while (!pq.empty()) {
            wep = pq.top(); pq.pop();
            hp -= wep.vill;
        }
    }
}