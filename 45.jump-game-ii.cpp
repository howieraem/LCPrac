/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(N)
    // S: O(1)
    int jump(vector<int>& nums) {
        int ans = 0, curFurthest = 0, curEnd = 0;
        const int last = nums.size() - 1;
        for (int i = 0; i < last; ++i) {
            curFurthest = max(curFurthest, i + nums[i]);
            if (i == curEnd) {
                // Do next jump.
                // This also applies to the base case i = 0
                curEnd = curFurthest;
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

