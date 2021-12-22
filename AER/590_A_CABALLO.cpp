#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int calcMin(vector<long long int> &vec, long long int min);

int main() {
	
	long long int celdas, uvas = 1;
	long long int aux; 
	bool stop;
	cin >> celdas;
	cin >> uvas;
	while(!(celdas == 0 && uvas == 0)) {
	    if (uvas == 0) {cout << 0 << endl;}
	    else {
	        stop = false;
    		vector<long long int> racimos;
    		if (!stop) {
    			for (int i = 0; i < celdas; ++i) {
    				cin >> aux;
    				stop = aux == uvas;
    				if (stop) {
    				    for (int j = i; j < (celdas - 1); ++j) {cin >> aux;}
    					cout << uvas << endl;
    					break;
    					}
    				else {racimos.push_back(aux);}
    			}
    			if (!stop) {
    				aux = calcMin(racimos, uvas);
    				if (aux >= uvas) {cout << aux << endl;}
    				else {cout << "IMPOSIBLE" << endl;}
    			}
    		}	
	    }
	    cin >> celdas;
	    cin >> uvas;
	}
	return 0;
}

long long int calcMin(vector<long long int> &vec, long long int min) {
	vector<long long int> sums; 
	int result = 0;
	for (int i = 0; i < vec.size(); ++i) {
		result = 0;
		for (int j = (0 + i); j < vec.size(); ++j) {
			result += vec[j];
			if (result == min) {return min;}
			if (result > min) {
				sums.push_back(result);
				break;
			}
		}
	}
	if (sums.empty()) {return 0;}
	sort(sums.begin(), sums.end());
	return sums[0];
}