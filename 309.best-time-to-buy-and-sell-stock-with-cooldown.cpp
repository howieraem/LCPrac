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
        
        // As many transactions as possible
        for (const int& price : prices) {
            int prev_sell = sell;

            // "sell" state can only be achieved from "buy" + selling
            sell = buy + price;

            // "buy" state can be achieved from "buy" or "cool" + buying
            buy = std::max(buy, cool - price);

            // "cool" state can be achieved from "cool" or former "sell"
            cool = std::max(cool, prev_sell);
        }

        return std::max(sell, cool);
    }
};
// @lc code=end

