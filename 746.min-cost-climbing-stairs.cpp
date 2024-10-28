/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // 1D DP
    // T: O(n)
    // S: O(1)
    int minCostClimbingStairs(const vector<int>& cost) {
        int fn_2 = cost[0], fn_1 = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            int cur = std::min(fn_2, fn_1) + cost[i];
            fn_2 = fn_1;
            fn_1 = cur;
        }
        return std::min(fn_2, fn_1);
    }
};
// @lc code=end

