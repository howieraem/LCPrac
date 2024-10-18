/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // Binary search
    // n := the number of entries, max := the maximum of the entries, min := the minimum of the entries
    // T: O(n * log(max - min)))
    // S: O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (cntSmallerOrEq(matrix, m) < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

private:
    // Each of the rows and columns is sorted in ascending order
    static int cntSmallerOrEq(vector<vector<int>>& mat, int mid) {
        int ans = 0;
        int col = mat[0].size() - 1;  // start with the rightmost col
        for (int row = 0; row < mat.size(); ++row) {
            // As row increases, the numbers are larger, 
            // and thus col may need to decrease
            while (col >= 0 && mat[row][col] > mid) { 
                --col;
            }
            ans += (col + 1);
        }
        return ans;
    }
};
// @lc code=end

