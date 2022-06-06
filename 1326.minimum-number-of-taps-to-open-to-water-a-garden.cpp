/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int minTaps(int n, vector<int>& ranges) {
        // Convert the problem representation.
        // can_reach[i] means the furthest position 
        // can be reached if currently at i.
        vector<int> can_reach(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            if (!ranges[i]) continue;
            int left = std::max(0, i - ranges[i]);
            can_reach[left] = std::max(
                    can_reach[left],
                    i + ranges[i]);
        }

        // Greedy, similar to Q45
        int ans = 0, cur_furthest = 0, cur_end = 0, i = 0;
        while (cur_end < n) {
            // Try skipping the ones already covered
            while (i <= n && i <= cur_end) {
                cur_furthest = std::max(cur_furthest,
                                        can_reach[i++]);
            }

            if (cur_end == cur_furthest)  return -1;

            // Move to next tap
            cur_end = cur_furthest;
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

