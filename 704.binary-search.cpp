/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] == target)  return m;
            else if (nums[m] > target)  r = m - 1;
            else  l = m + 1;
        }
        return -1;
    }
};
// @lc code=end

