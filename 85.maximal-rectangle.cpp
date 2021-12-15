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
    // T: O(m * n)
    // S: O(n)
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        // Converts the problem to finding the max. reactangle area
        // like Question 84
        vector<int> heights(n + 2, 0);  // zero-padded left and right by 1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++heights[j + 1];
                } else {
                    heights[j + 1] = 0;
                }
            }
            // now `heights` should look like [0, h0, h1, ..., hn, 0]
            ans = max(ans, largestHistRectArea(heights));
        }
        return ans;
    }

private:
    static int largestHistRectArea(vector<int> &heights) {
        int ans = 0;
        stack<int> s;    // mono-stack that stores indices
        for (int i = 0; i < heights.size(); ++i) {
            while (s.size() && heights[s.top()] > heights[i]) {
                int tmp = s.top(); s.pop();
                ans = max(ans, (i - s.top() - 1) * heights[tmp]);
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

