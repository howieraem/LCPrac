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
    // two pointers
    // T: O(n)
    // S: O(1)
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int x : nums) {
            if (x != 0) {
                nums[i++] = x;
            }
        }

        // now, all numbers at i and onwards should be zeroed
        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};
// @lc code=end

