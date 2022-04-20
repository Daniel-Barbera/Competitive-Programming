#include <iostream>
#include <set>
#include <vector>
#include <math.h>
using namespace std;

int calculateSumOfCubes(int num) {
    int sumOfCubes = 0;
    vector<short> digits;
    while (num != 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    for (short d: digits) {
        sumOfCubes += pow(d, 3);
    }
    return sumOfCubes;
}

string isCubefinite(int num, set<int> &serie) {
    if (num == 1) {
        serie.clear();
        return to_string(num) + " -> cubifinito.\n";
    } else if (serie.find(num) != serie.end()) {
        serie.clear();
        return to_string(num) + " -> no cubifinito.\n";
    } else {
        serie.insert(num);
        int sumOfCubes = calculateSumOfCubes(num);
        return to_string(num) + " - " + isCubefinite(sumOfCubes, serie);
    }
}

int main() {
    int num = 1;
    set<int> serie;
    while (cin >> num) {
        if (num == 0) return 0;
        else cout << isCubefinite(num, serie);
    }

    return 0;
}