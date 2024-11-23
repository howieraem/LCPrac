/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
#include <algorithm>
#include <stack>
#include <vector>

using std::max;
using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
    // Mono-stack + 1D DP (heights array)
    // T: O(m * n)
    // S: O(n)
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        // Converts the problem to finding the max. rectangle area of histograms Q84
        // Add a zero height at the right to make the helper function elegant 
        // (see explanations in Q84)
        vector<int> heights(n + 1, 0);  
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++heights[j];
                } else {
                    // the "histogram" bar cannot contain a zero in the middle
                    heights[j] = 0;
                }
            }
            // now `heights` should look like [h(0), h(1), ..., h(n-1), 0]
            ans = max(ans, largestHistRectArea(heights));
        }
        return ans;
    }

private:
    static int largestHistRectArea(vector<int> &heights) {
        int ans = 0;
        stack<int> st;    // mono-stack that stores indices of heights (ordered ASC)
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                const int& h = heights[st.top()]; st.pop();
                int pre_i = st.empty() ? -1 : st.top();  // -1 handles pure DESC input heights
                int w = i - 1 - pre_i;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

