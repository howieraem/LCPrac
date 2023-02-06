/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        // res[0] = 0;

        // DP: res[i / 2] is the number of set bits of a number with a bit less,
        // and i % 2 determines whether the newly appended bit is set.
        for (int i = 1; i <= n; ++i) {
            // if (i % 2 == 0) {
            //    ans[i] = ans[i / 2];
            // } else {
            //    ans[i] = ans[i - 1] + 1;
            // }

            // Equivalent approach
            // res[i] = res[i / 2] + i % 2;
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
};
// @lc code=end

