/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int maxProfit(vector<int>& prices) {
        int sell = 0, buy = INT_MIN, cool = 0;
        
        // buy[i] = max(cool[i - 1] - prices[i], buy[i - 1])
        // sell[i] = max(buy[i - 1] + prices[i], sell[i - 1])
        // cool[i] = max(sell[i - 1], cool[i - 1])

        // As many transactions as possible
        for (const int& price : prices) {
            int prev_sell = sell;

            // "sell" state can only be achieved from "buy" + selling
            sell = buy + price;

            // "buy" state can be achieved from "buy" or "cool" + buying
            buy = std::max(buy, cool - price);

            // "cool" state can be achieved from "cool" or former "sell"
            // Note that it's possible to cool down for more than 1 day
            cool = std::max(cool, prev_sell);
        }

        return std::max(sell, cool);
    }
};
// @lc code=end

