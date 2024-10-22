/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {

            // Make nums[i] = nums[nums[i] - 1]. For example, if 5 is in nums, 
            // after swapping, nums[4] = 5.
            // If 1, 2, 3 and 4 are in nums, after swapping we have nums = {1, 2, 3, 4, ...},
            // so it will be easy to find the first missing positive number.
            // This while loop is guaranteed to be finite as the max no. of "wrongly"
            // placed numbers is n.
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first index such that nums[index] != index + 1.
        // The smallest missing positive number is index + 1. 
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // nums is now [0, 1, 2, ..., n]. Nothing missing between 0 and n.
        // Thus, n + 1 is the smallest missing positive number. 
        return n + 1;
    }
};
// @lc code=end

