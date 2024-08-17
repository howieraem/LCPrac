/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <bits/stdc++.h>

using std::vector;
using std::max;
using std::min;

// @lc code=start
class Solution {
public:
    // Solution 1
    // T: O(n)
    // S: O(1)
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            // Buy stock or not
            buy_price = min(buy_price, prices[i]);

            // Sell stock or not
            ans = max(ans, prices[i] - buy_price);
        }
        return ans;
    }
};
// @lc code=end

