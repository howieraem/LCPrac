/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto &n : nums) {
            sum += n;
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (leftSum == sum - nums[i] - leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

