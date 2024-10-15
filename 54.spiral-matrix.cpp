/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(1) ignoring the result container
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        int left = 0; 
        int right = n - 1; 
        int top = 0; 
        int bottom = m - 1;

        vector<int> res(m * n);
        int p = 0;
        
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                res[p++] = matrix[top][i];
            }

            for (int j = top + 1; j <= bottom; ++j) {
                res[p++] = matrix[j][right]; 
            }

            if (left < right && top < bottom) {
                for (int i = right - 1; i > left; --i) {
                    res[p++] = matrix[bottom][i];
                }
                for (int j = bottom; j > top; --j) {
                    res[p++] = matrix[j][left];
                }
            }
            ++left; 
            --right; 
            ++top; 
            --bottom;
        }
        return res;
    }
};
// @lc code=end

