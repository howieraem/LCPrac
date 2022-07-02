/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <vector>
#include <utility>

using std::vector;
using std::swap;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    void sortColors(vector<int>& nums) {
        int p = 0, p0 = 0, p2 = nums.size() - 1;

        // after looping: 
        // for all i < p0, nums[i] = 0;
        // for all i > p2, nums[i] = 2.
        while (p <= p2) {
            if (nums[p] == 0) {
                swap(nums[p++], nums[p0++]);
            } else if (nums[p] == 2) {
                swap(nums[p], nums[p2--]);
            } else {
                ++p;
            }
        }
    }
};
// @lc code=end

