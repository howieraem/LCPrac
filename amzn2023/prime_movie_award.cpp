/**
 * Split movie awards into groups, such that the difference between the max award and 
 * the min award in each group is less than k. Return the minimum number of groups 
 * where each movie can only appear in one group.
 */
#include <bits/stdc++.h>

// T: O(n * log(n))
// S: O(log(n))? for std::sort()
int min_groups(const std::vector<int>& awards, int k) {
    std::sort(awards.begin(), awards.end());
    int ans = 1, cur_min = awards[0];
    for (int i = 1; i < awards.size(); ++i) {
        if (std::abs(awards[i] - cur_min) > k) {
            ++ans;
            cur_min = awards[i];
        }
    }
    return ans;
}
