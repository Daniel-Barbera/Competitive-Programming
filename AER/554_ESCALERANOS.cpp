#include <bits/stdc++.h>
using namespace std;

int maxSteps, numSteps;
int steps[10];
array<int, 105> memo;

int count_DP(int stepsTaken) {
    if (stepsTaken < 0) return 0;
    if (stepsTaken == 0) return 1;
    if (memo[stepsTaken] != -1) return memo[stepsTaken];
    memo[stepsTaken] = 0;
    for (int i = 0; i < numSteps; ++i) {
        memo[stepsTaken] = (
            memo[stepsTaken] % 1000000007 + count_DP(stepsTaken - steps[i]) % 1000000007)
            % 1000000007;
    }
    return memo[stepsTaken];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> maxSteps && maxSteps) {
        memo.fill(-1);
        cin >> numSteps;
        for (int i = 0; i < numSteps; ++i) {
            cin >> steps[i];
        }
        cout << count_DP(maxSteps) << '\n';
    }
}