/*
 * @lc app=leetcode id=1375 lang=cpp
 *
 * [1375] Number of Times Binary String Is Prefix-Aligned
 */

#include <algorithm>

using std::max;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0, rightmost = 0;
        for (int i = 0; i < flips.size(); ++i) {
            rightmost = max(rightmost, flips[i]);

            // If the index of rightmost bit flipped equals to
            // the number of bits flipped, then all the bits
            // flipped are on the left.
            ans += (rightmost == i + 1); 
        }
        return ans;
    }
};
// @lc code=end

