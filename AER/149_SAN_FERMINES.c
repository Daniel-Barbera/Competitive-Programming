#include <stdio.h>

int main() { 
    int numSpeeds, s, mx;
    while (scanf("%d", &numSpeeds) == 1) {
        mx = 0;
        while (numSpeeds--){
            scanf("%d", &s);
            mx = (mx > s) ? mx : s;
        }
        printf("%d\n", mx);
        }
    return 0;
}