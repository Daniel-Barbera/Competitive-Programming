#include <bits/stdc++.h>
using namespace std;


int main() {

    int numCasos, cents, i;
    int twoDaysBefore, dayBefore, crtDay, crtCents; 

    scanf("%d", &numCasos);
    while (numCasos--) {
        scanf("%d", &cents);

        if (cents == 1) printf("1\n");
        else if (cents == 2) printf("2\n");
        else {  
            twoDaysBefore = 1, dayBefore = 1; crtCents = 2;
            i = 3;
            while (true) {
                crtDay = 2*twoDaysBefore + dayBefore; 
                crtCents += 2*twoDaysBefore + dayBefore;
                twoDaysBefore = dayBefore;
                dayBefore = crtDay; 
                if (crtCents >= cents) break;
                ++i;
            }
            printf("%d\n", i);
        }
    }
}