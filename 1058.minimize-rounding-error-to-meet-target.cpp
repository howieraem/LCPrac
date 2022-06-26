/*
 * @lc app=leetcode id=1058 lang=cpp
 *
 * [1058] Minimize Rounding Error to Meet Target
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    string minimizeError(vector<string>& prices, int target) {
        std::priority_queue<double> max_heap;
        int sum = 0;
        // Only considering floor here
        for (const auto& pr : prices) {
            auto price = std::stod(pr), floor_price = std::floor(price);
            sum += floor_price;
            auto diff = price - floor_price;
            if (diff > 0) {
                max_heap.push(diff);
            }
        }

        // Check if sum is too large or too small
        if (sum > target || sum < target - max_heap.size()) {
            return "-1";
        }

        int diff = target - sum;
        double err = 0;
        while (max_heap.size()) {
            auto f_diff = max_heap.top(); max_heap.pop();
            // When diff > 0 convert to price - ceil(price) because f_diff is larger
            // in the beginning, i.e. should round by ceil(). The rest should use 
            // f_diff, i.e. round by floor(). 
            err += diff > 0 ? 1 - f_diff : f_diff;
            --diff;
        }
        string ans = std::to_string(err);
        return ans.substr(0, ans.find('.') + 4);
    }
};
// @lc code=end

