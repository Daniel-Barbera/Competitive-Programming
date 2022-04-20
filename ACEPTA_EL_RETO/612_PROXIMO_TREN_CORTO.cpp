#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    vector<long long> platform, forwards, backwards;
    long long num, distanceTraveled, passengers, trainLength, platformSize, minDistance; 
    while (scanf("%lld %lld", &trainLength, &platformSize) && (trainLength || platformSize)) {
        for (int i = 0; i < platformSize; ++i) {
            scanf("%lld", &num);
            platform.push_back(num);
        }
        
        distanceTraveled = passengers = 0;
        forwards.push_back(0);
        for (int i = 0; i < platformSize - trainLength; ++i) {
            passengers += platform[i];
            distanceTraveled += passengers;
            forwards.push_back(distanceTraveled);
        }
        
        distanceTraveled = passengers = 0;
        backwards.push_back(0);
        for (int j = platform.size() - 1; j >= trainLength; --j) {
            passengers += platform[j];
            distanceTraveled += passengers;
            backwards.push_back(distanceTraveled);
        }

        minDistance = numeric_limits<long long>::max();
        vector<long long>::iterator it = forwards.begin();
        vector<long long>::reverse_iterator rit = backwards.rbegin();

        while (it != forwards.end()) {
            minDistance = min(minDistance, *it + *rit);
            ++it; ++rit;
        }

        printf("%lld\n", minDistance);
        platform.clear(); forwards.clear(); backwards.clear(); 
    }

    return 0; 
}