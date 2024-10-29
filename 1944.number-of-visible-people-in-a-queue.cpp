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
    // Mono-stack
    // T: O(n)
    // S: O(n)
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n);
        stack<int> stk;   // Mono-stack with indexes of DESC heights.
        for (int i = 0; i < n; ++i) {
            // Suppose the current element is h, and 
            // the stack top element has index i in the input.
            while (!stk.empty() && heights[stk.top()] <= heights[i]) {
                // If that element's height <= h,
                // it can see h, so we increment res[i]++.
                // Because h is tall and block the line of sight.
                // that element can't see any element after h,
                // we have done the work for it, 
                // so we stack.pop() it from the stack.
                ++res[stk.top()];
                stk.pop();
            }
            if (!stk.empty()) {
                // If stack is not empty at this point, that element 
                // will be the left next greater element of h, and 
                // it can still see h, so increment res[i]++.
                ++res[stk.top()];
            }
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

