/*
 * @lc app=leetcode id=1944 lang=cpp
 *
 * [1944] Number of Visible People in a Queue
 */
#include <bits/stdc++.h>

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            // mono-stack with indexes of DESC heights
            while (!stk.empty() && heights[stk.top()] <= heights[i]) {
                ++res[stk.top()];
                stk.pop();
            }
            if (!stk.empty()) {
                ++res[stk.top()];
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

