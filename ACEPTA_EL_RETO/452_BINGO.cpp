#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <stdlib.h>
using namespace std;

void calcSet (set<int, less<int>> &set, vector<int> &vec);
int main() {
	
	int numCases = 0;
	int input = 0;
	cin >> numCases;
	while(numCases != 0) {
		set<int, less<int>> boardNums;
		vector<int> nums;
		for (int i = 0; i < numCases; ++i) {
			cin >> input;
			nums.push_back(input);
		}
		calcSet(boardNums, nums);
		auto it = boardNums.begin();
        while (it != boardNums.end()) {
            auto aux = it;
            ++aux;
            if (aux == boardNums.end()) {cout << *it << endl;}
            else {cout << *it << ' ';}
            ++it;
        }
		cin >> numCases;
	}
	
	return 0;
}

void calcSet(set<int, less<int>> &set, vector<int> &vec) {
	int aux = 0;
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = i; j < vec.size(); ++j) {
			aux = abs(vec[i] - vec[j]);
			if (aux != 0) set.insert(aux);
		}
	}
}