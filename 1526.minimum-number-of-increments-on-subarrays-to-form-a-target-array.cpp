/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Greedy
    // T: O(n)
    // S: O(1)
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        if (n == 0) {
            return 0;
        }

        // Reverse thinking: Whenever there is a local maximum, level it with the next second highest
        // Example: 
        // 1. [3, 1, 1, 2] -> [1, 1, 1, 2] takes 2 ops
        // 2. [1, 1, 1, 2] -> [1, 1, 1, 1] takes 1 ops
        // 3. [1, 1, 1, 1] -> [0, 0, 0, 0] takes 1 ops
        int ans = target[0];
        for (int i = 1; i < target.size(); ++i) {
            ans += std::max(target[i] - target[i - 1], 0);
        }
        return ans;
    }
};
// @lc code=end

