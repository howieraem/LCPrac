/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // mono-stack
    // T: O(n)
    // S: O(n)
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<int> st; // Stores index of height (in ASC order of height)

        // Add a 0 at the end to treat bars as rising and falling edges (each bar has width 1), 
        // and to avoid extra logic to calculate areas in the last iteration 
        // (e.g., if the input heights are ordered ASC)
        heights.push_back(0);

        int ans = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                const int& h = heights[st.top()]; st.pop();
                int pre_i = st.empty() ? -1 : st.top();  // -1 handles pure DESC input heights
                int w = i - pre_i - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }

        return ans;
    }
};
// @lc code=end

