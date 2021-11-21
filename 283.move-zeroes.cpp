/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i > j) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                ++j;
            }
        }
    }
};
// @lc code=end

