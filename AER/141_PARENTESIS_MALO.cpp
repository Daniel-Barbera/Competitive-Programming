#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool isBalanced(vector<char> vec);

int main() {
	
	string input;
	set<char> dictionary = {'(', ')', '[', ']', '{', '}'};
	
	while (!cin.eof()) {
	    
		getline(cin, input);
		vector<char> vec;
		
		// Añadir datos relevantes a vector
		for (int i = 0; i < input.length(); ++i) {
			if (dictionary.find(input[i]) != dictionary.end()) {
			    vec.push_back(input[i]);
			}
		}
		if (isBalanced(vec)) {cout << "YES" << endl;}
		else {cout << "NO" << endl;}
		
	}
	return 0;
}

bool isBalanced(vector<char> vec) {
	
	if (vec.empty()) {return true;}
	else {
	    bool stop = false;
		int i = 1;
		
		if (vec.size() < 2) {return false;}
		
		while (!stop) {
			switch(vec[i]) {
				case ')':
					if (vec[i-1] == '(') {
						vec.erase(vec.begin()+(i-1), vec.begin()+(i+1));
						return (isBalanced(vec));
					}
					break;
				case ']':
					if (vec[i-1] == '[') {
						vec.erase(vec.begin()+(i-1), vec.begin()+(i+1));
						return (isBalanced(vec));
					}
					break;
				case '}':
				if (vec[i-1] == '{') {
						vec.erase(vec.begin()+(i-1), vec.begin()+(i+1));
						return (isBalanced(vec));
					}
					break;
			}
			++i;
			stop = (i == vec.size()) && (!vec.empty());
		}
		return !stop;
	}
}
