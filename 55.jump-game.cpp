/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int curFurthest = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= curFurthest) {
                if ((curFurthest = max(curFurthest, i + nums[i])) >= n - 1) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

