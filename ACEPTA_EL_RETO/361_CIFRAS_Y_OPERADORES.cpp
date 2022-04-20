#include <bits/stdc++.h>
using namespace std;

array<int, 5> nums;
constexpr int numOps = 4;
long long int target;


bool backtracking (int arrayPosition, long long int num) {
    if (arrayPosition == nums.size()) return num == target;

    long long int aux = num;
    for (int operand = 0; operand < numOps; ++operand) {
        switch(operand) {
            // 0 -> suma, 1 -> resta, 2 -> mult, 3 -> división
            case 0:
                aux = num + nums[arrayPosition];
                break;
            case 1:
                aux = num - nums[arrayPosition];
                break;
            case 2:
                aux = num * nums[arrayPosition];
                break;
            case 3:
                if (nums[arrayPosition] == 0 || num % nums[arrayPosition] != 0) continue;
                aux = num / nums[arrayPosition];
                break;
        }
        if (backtracking(arrayPosition + 1, aux)) return true;
    }
    return false;
}

int main() {

    while (scanf("%lld", &target) == 1) {
        for(int i = 0; i < 5; ++i) scanf("%d", &nums[i]);
        // (1, 0, nums[0]) -> sobre el primer elemento (nums[0]) no se hace nada
        // debemos empezar a operar con nums[0] =op= nums[1]
        backtracking(1, nums[0]) ? printf("SI\n") : printf("NO\n");
    }

    return 0;
}