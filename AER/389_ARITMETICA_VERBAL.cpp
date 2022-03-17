#include <bits/stdc++.h>
using namespace std;


struct state {
    int digit;
    array<bool, 10> visited;
    state(){}
    state(int digit){
        this->digit = digit;
        visited.fill(0);
    }
    state(int digit, array<bool, 10> visited){
        this->digit = digit;
        this->visited = visited;
    }
};

void solve() {
    
}


int main() {
    unordered_map<char, state> code;
    string lhs, op, rhs, sol;
    while (cin >> lhs >> op >> rhs >> sol >> sol) {
        for (auto it: lhs) code[it] = state(0);
        for (auto it: rhs) code[it] = state(0);
        for (auto it: sol) code[it] = state(0);
        //solve();
        for (auto it: lhs) cout << code[it].digit;
        cout << ' ' << op << ' ';
        for (auto it: rhs) cout << code[it].digit;
        cout << " = ";
        for (int i = 0; i < sol.size() - 1; ++i) cout << code[sol[i]].digit;
        cout << code[*sol.rbegin()].digit << '\n';
    }

    return 0;
}