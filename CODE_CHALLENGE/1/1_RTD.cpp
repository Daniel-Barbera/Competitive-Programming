#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	
	ifstream input;
	input.open("C:/Users/anton/Desktop/SOLUCIONES_CP/CODE_CHALLENGE/1/submitInput.txt", ios::in);

    ofstream output;
    output.open("C:/Users/anton/Desktop/SOLUCIONES_CP/CODE_CHALLENGE/1/submitOutput.txt", ios::out);

	if (!input.is_open()) {return -1;}
    else {
        int numCases;
        input >> numCases;

        string testCase;
        int roll1, roll2, sum;
        const int MAX = 12;

        // Solución simple, pero que habría que tunear si el número de caras del dado fuera superior a 9.
        for(int i = 1; i <= numCases; ++i) {
            input >> testCase;

            // Char to int conv.
            roll1 = testCase[0] - '0';
            roll2 = testCase[2] - '0';

            sum = roll1 + roll2 + 1;

            if (sum > MAX) {output << "Case #" << i << ": " << '-' << endl;}
            else {(output << "Case #" << i << ": " << sum << endl);}
        }  
    }

    input.close();
    output.close();

	return 0;
}