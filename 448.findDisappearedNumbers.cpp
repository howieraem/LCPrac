/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include <vector>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int newIdx = abs(nums[i]) - 1;  // abs() because element might have been visited
            if (nums[newIdx] > 0)  nums[newIdx] *= -1;   // visited
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)  res.emplace_back(i+1);
        }
        return res;
    }
};
// @lc code=end

