#include <stdio.h>
#include <math.h>

int main() {
    int numTransacts;
    int sum, num, max;
    while (scanf("%d", &numTransacts) && numTransacts) {
        sum = max = 0;
        while (numTransacts--) {
            scanf("%d", &num);
            sum += num;
            if (sum > max) max = sum;
        }
        printf("%d %d\n", sum, max);
    }

    return 0;
}