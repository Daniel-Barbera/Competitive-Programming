#include <bits/stdc++.h>
using namespace std; 

int main() {
    int numCases, num;
    string number, lFang, rFang, permutation;
    cin >> numCases;
    while (numCases--) {
        cin >> number;
        permutation = number;
        num = stoi(number); 

        if (number.length() % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        
        next_permutation(permutation.begin(), permutation.end());
        bool vampire = false;
        while (permutation != number && !vampire) {
            lFang = permutation.substr(0, permutation.length()/2);
            rFang = permutation.substr(permutation.length()/2);
            int result = stoi(lFang) * stoi(rFang);
            vampire = result == num && (lFang.back() - '0' || rFang.back() - '0');
            next_permutation(permutation.begin(), permutation.end());
        }
        vampire ? cout << "SI\n" : cout << "NO\n";
    }
    return 0; 
}