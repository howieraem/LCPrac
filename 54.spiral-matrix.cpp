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

    /*
    // Follow-up: different direction with skipped elements
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int left = 0, right = n - 1, top = 0, bottom = m - 1, p = 0;
        bool keep = true;
        while (left <= right && top <= bottom) {
            for (int i = top; i <= bottom; ++i) {
                if (keep) {
                    res[p++] = matrix[i][left];
                }
                keep = !keep;
            }

            for (int j = left + 1; j <= right; ++j) {
                if (keep) {
                    res[p++] = matrix[bottom][j]; 
                }
                keep = !keep;
            }

            if (left < right && top < bottom) {
                for (int i = bottom - 1; i > top; --i) {
                    if (keep) {
                        res[p++] = matrix[i][right];
                    }
                    keep = !keep;
                }
                for (int j = right; j > left; --j) {
                    if (keep) {
                        res[p++] = matrix[top][j];
                    }
                    keep = !keep;
                }
            }
            ++left; --right; ++top; --bottom;
        }
        return res;
    }
    */
};
// @lc code=end

