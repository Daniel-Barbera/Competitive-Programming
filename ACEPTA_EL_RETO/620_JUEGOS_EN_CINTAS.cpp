#include <bits/stdc++.h>
using namespace std; 

int sideSize, numGames;
vector<int> games;

bool solve(int sizeA, int sizeB, int idx) {
    if (sizeA > sideSize || sizeB > sideSize) return false;
    if (idx == games.size() && sizeA <= sideSize && sizeB <= sideSize) return true;

    return solve(sizeA + games[idx], sizeB, idx + 1) || solve(sizeA, sizeB + games[idx], idx + 1);  
}

int main() {
    while (cin >> sideSize >> numGames) {
        int game;
        while (numGames--) {
            cin >> game;
            games.push_back(game);
        }
        solve(0, 0, 0) ? cout << "SI\n" : cout << "NO\n";
        games.clear();
    }
    return 0; 
}