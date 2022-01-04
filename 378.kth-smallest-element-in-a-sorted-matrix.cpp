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
    // n := the number of entries, max := the maximum of the entries, min := the minimum of the entries
    // T: O(n * log(max - min)))
    // S: O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (cntSmaller(matrix, m) < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

private:
    // Each of the rows and columns is sorted in ascending order, 
    // i.e. the last entry of the current row is less than 
    // the first entry of the next row.
    static int cntSmaller(vector<vector<int>>& mat, int mid) {
        int ans = 0;
        for (int i = 0, j = mat[0].size() - 1; i < mat.size() && j >= 0; i++) {
            while (j >= 0 && mat[i][j] > mid)  --j;
            ans += (j + 1);
        }
        return ans;
    }
};
// @lc code=end

