/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // "Flatten" the matrix and do binary search
    // T: O(log(m * n))
    // S: O(1) 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;   // might need to check overflow
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int r = mid / n; 
            int c = mid % n;
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

