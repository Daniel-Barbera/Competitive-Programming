#include <iostream>
using namespace std;

unsigned long long int factorial(int num) {
	unsigned long long int result;
	if (num == 0) return 1;
	else result = num * factorial(num-1);
	return result;
}

int lastDigit(unsigned long long int num) {	
	return num % 10;
}

int main () {
	int testCases;
	int currentCase;
	cin >> testCases;
	while (testCases != 0) {
		cin >> currentCase;
		cout << lastDigit(factorial(currentCase)) << endl;
		--testCases;
	}
	
	return 0;
}