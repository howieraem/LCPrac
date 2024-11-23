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
        // (e.g., if all input heights are already ordered ASC)
        heights.push_back(0);

        int ans = 0;

        for (int i = 0; i < heights.size(); ++i) {
            // When clearing higher bars, update max rectangle area as well
            while (!st.empty() && heights[st.top()] > heights[i]) {
                const int& h = heights[st.top()]; st.pop();
                // pre_i is the index of the previous higher bar after poping the first higher bar 
                // i - 1 represents the right boundary of the considered rectangle, and stack top now 
                // represents the left boundary. Thus, w = i - 1 - pre_i.
                // Set pre_i to -1 to handle empty stack, i.e. pure DESC input heights.
                int pre_i = st.empty() ? -1 : st.top();  
                int w = i - 1 - pre_i;
                ans = max(ans, h * w);
            }
            st.push(i);
        }

        return ans;
    }
};
// @lc code=end

