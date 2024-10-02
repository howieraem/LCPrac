/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Greedy
    // T: O(n)
    // S: O(1)
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }

        int ans = 1;  // for ratings[0]
        int up = 0;  // how many children have increasing ratings from the last child
        int down = 0;  // how many children have decreasing ratings from the last child
        int peak = 0;  // last highest point in an increasing subarray of ratings
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i - 1] < ratings[i]) {
                down = 0;
                peak = ++up;
                ans += 1 + up;
            } else if (ratings[i - 1] == ratings[i]) {
                up = 0;
                down = 0;
                peak = 0;
                ans += 1;
            } else {
                up = 0;
                ++down;
                // The peak child should get additional candies 
                // if the decreasing subarray is longer than 
                // the previous increasing subarray
                ans += down + (peak < down);
            }
        }
        return ans;
    }
};
// @lc code=end

