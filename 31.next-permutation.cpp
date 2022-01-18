/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    // T: O(n)
    // S: O(1)
    void nextPermutation(vector<int>& nums) {
        // Step 1: 
        //     Find the largest index i such that nums[i] < nums[i + 1].
        //     If no such index exists (i becomes -1, the array is found
        //     sorted descendingly), then reverse the entire array so
        //     that the order becomes the lowest (sorted acendingly).
        int i;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; --i);

        if (i >= 0) {
            // Step 2: Find the largest index j > i such that nums[i] < nums[j].
            int j;
            for (j = nums.size() - 1; j >= 0 && nums[i] >= nums[j]; --j);

            // Step 3: Swap nums[i] and nums[j].
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the subarray nums[i + 1:]. Below also works if i is -1.
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

