#include <bits/stdc++.h>
using namespace std;

int main() {
    int numCasos, num;
    scanf("%d\n", &numCasos);
    while (numCasos--) {
        char input[7];
        gets(input);
        int l = strlen(input);
        int sz = l - 3;
        string output;
        for (int i = 0; sz >= 0; ++i) {
            output += input[i];
            --sz;
        }
        printf("%s\n", output.c_str());
        output.clear();
    }
}