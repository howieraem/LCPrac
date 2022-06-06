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
    /*
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
    */

    // A more general solution: 
    // if can't reaching the last index, return -1
    // T: O(n)
    // S: O(1)
    int jump(vector<int>& nums) {
        // cur_furthest can represent all the furthest possible reachable positions, while 
        // cur_end means the furthest reachable position after a jump/step/action performed.
        int ans = 0, cur_furthest = 0, cur_end = 0, i = 0;
        const int dst = nums.size() - 1;
        while (cur_end < dst) {
            while (i < nums.size() && i <= cur_end) {
                cur_furthest = max(cur_furthest, i + nums[i++]);
            }
            // cur_furthest is the same as the furthest reachable position of the previous step,
            // so impossible to move forward.
            if (cur_end == cur_furthest)  return -1;

            // Jump and update cur_end
            cur_end = cur_furthest;
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

