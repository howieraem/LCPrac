/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Greedy + Sorting
    // T: O(n * log(n))
    // S: O(n)
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        const int n = dist.size();
        
        // convert to remaining time
        vector<double> remaining_time(n);
        for (int i = 0; i < n; ++i) {
            if (speed[i] == 0) {
                remaining_time[i] = (double)INT_MAX;
            } else {
                remaining_time[i] = (double)dist[i] / speed[i];
            }
        }

        std::sort(remaining_time.begin(), remaining_time.end());
        
        double cur_t = 0.;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (remaining_time[i] > cur_t) {
                ++ans;
            } else {
                return ans;
            }
            cur_t += 1.0;
        }
        
        return ans;
    }
};
// @lc code=end

