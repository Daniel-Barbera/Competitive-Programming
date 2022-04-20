#include <bits/stdc++.h>
using namespace std;


unordered_map<char, int> charmap;
vector<char> keys;
string lhs, op, rhs, sol;

long long map_operand(string num) {
    for (int i = 0; i < num.size(); ++i) {
        num[i] = charmap[num[i]];
    }
    return stoll(num);
}


void solve_sum(int val, int idx) {
    if (idx > 
    char crt = keys[idx];
    for (auto kv: charmap) {
        if 
    }
    if (map_operand(lhs) + map_operand(rhs) == map_operand(sol)) {
        // save all values to map
        return;
    }
    else {
        
    }
}

void solve_mult() {

}


int main() {
    unordered_set<char> charset;
    
    while (cin >> lhs >> op >> rhs >> sol >> sol) {
        // Extract unique chars
        for (char c: lhs) charset.insert(c);
        for (char c: rhs) charset.insert(c);
        for (char c: sol) charset.insert(c);
        for (char c: charset) {
            charmap[c] = 0;
            keys.push_back(c);
        }

        const long long MAX_VALUE = pow(10, charmap.size()); 

        // Try all possible combinations
        if (op == "*") solve_mult();
        else solve_sum();

        cout << map_operand(lhs) << " " << op << " " << map_operand(rhs) << " = " << map_operand(sol) << '\n';
        charmap.clear();
        charset.clear();
        keys.clear();
    }

    return 0;
}