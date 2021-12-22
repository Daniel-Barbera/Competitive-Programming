#include <iostream>
using namespace std;

int main() {
	
	int input = 0;
	bool stop = false;
	
	while (!cin.eof()) {
		cin >> input;
		stop = input == 42;
		if (!stop) cout << input << endl;
		else break;
	}
	
	while(!cin.eof()) cin >> input;
	
	return 0;
	
}
