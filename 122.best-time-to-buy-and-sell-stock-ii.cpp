/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            ans += std::max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
};
// @lc code=end

