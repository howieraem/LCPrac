/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Solution 1: 2D DP, iteratively update the array from the end to the beginning
    // T: O(rowIndex ^ 2)
    // S: O(1) excl. output
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {  
                // Iterate from back to front, so that numbers updated 
                // will not affect those not yet updated.
                // Correct sequence:
                // [1, nil, ..., nil]
                // -> [1, 1, nil, ..., nil]
                // -> [1, 2, 1, nil, ..., nil]
                // -> [1, 3, 3, 1, nil, ..., nil] 
                // -> ...
                // If iterating from front to back, the result will be obviously wrong.
                res[j] += res[j - 1];
                // res[j] = res[j] + res[j - 1];
            }
        }
        return res;
    }

    /*
    // Solution 2: Math, based on the fact that the ith element on the nth row is C(n, i)
    // T: O(rowIndex)
    // S: O(1)
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res.front() = 1;
        // res.back() = 1;

        for (int i = 1; i <= rowIndex; ++i) {
            // C(n, i) = C(n, i - 1) * (n - i + 1) / i
            res[i] = 1LL * res[i - 1] * (rowIndex - i + 1) / i;
            // long ret = static_cast<long>(res[i - 1]) * (rowIndex - i + 1) / i;
            // res[i] = static_cast<int>(ret);
        }
        return res;
    }
    */
};
// @lc code=end

