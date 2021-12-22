#include <iostream>
using namespace std;

int main() {
	
	int numTests = 0;
	long long int m, n = 0;
	cin >> numTests;
	
	bool isPrime = false;
	for (int i = 0; i < numTests; ++i) {
		cin >> m;
		cin >> n;
		for (int j = m; j <= n; ++j) {
			for (int k = 2; k <= j; ++k) {
				isPrime = j % k != 0;
				if (!isPrime) break;
				if (k == n && isPrime) cout << k << endl;
			}
		}
		cout << endl;
	}
	
	return 0;
}