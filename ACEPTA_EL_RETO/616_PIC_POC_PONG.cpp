#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    bool leftIsAttacking;
    int numSounds, lScore, rScore; 
    string sound; 
    while (cin >> numSounds && numSounds) {
        leftIsAttacking = true; 
        lScore = rScore = 0;
        while (numSounds--) {
            cin >> sound;
            if (sound == "PIC") {
                leftIsAttacking = !leftIsAttacking; 
            } else if (sound == "PONG!") {
                leftIsAttacking ? ++lScore : ++rScore;
            }
        }
        cout << lScore << ' ' << rScore << '\n';
    }
    return 0; 
}