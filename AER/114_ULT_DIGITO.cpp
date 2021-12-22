#include <iostream>
using namespace std;

int factLastDigit(int num) {
		switch(num) {
    		case 0: return 1;
    		case 1: return 1;
    		case 2: return 2;
    		case 3: return 6;
    		case 4: return 4;
    		default: return 0;
		}
}

int main () {
	int testCases;
	int currentCase;
	cin >> testCases;
	while (testCases != 0) {
		--testCases;
		cin >> currentCase;
		cout << factLastDigit(currentCase) << endl;
	}
	
	return 0;
}