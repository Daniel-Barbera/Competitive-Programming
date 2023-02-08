#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> input, int target) {
    unordered_map<int, vector<int>> map;
    int idx = 0;
    for (int number: input) {
        map[number].push_back(idx);
        ++idx;
    }
    for (auto &iterator: map) {
        int difference_with_target = abs(target - iterator.first);
        if (target < iterator.first) difference_with_target *= -1;
        auto reference_to_solution = map.find(difference_with_target);
        if (reference_to_solution == map.end()) continue;
        if (difference_with_target == iterator.first) {
            vector<int> indexes = reference_to_solution->second;
            if (indexes.size() < 2) {
                continue;
            }
            return vector<int>(indexes.begin(), indexes.begin() + 2);
        }
        vector<int> solution = { iterator.second[0], reference_to_solution->second[0] };
        return solution;
    }
    return vector<int>();
}
