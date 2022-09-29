/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <bits/stdc++.h>

using std::swap;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * n!)
    // S: O(n) for result copying
    vector<vector<int>> permute(vector<int>& nums) {
        // When nums are unique, the number of permutations is n!
        size_t res_sz = 1, n = nums.size();
        while (n > 1) {
            res_sz *= n--;
        }
        vector<vector<int>> res;
        res.reserve(res_sz);

        backtrack(nums, 0, res);
        return res;
    }

private:
    // Explanation of a similar problem: 
    // https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
    // In each layer of the recursion tree, nums[:begin] is fixed, and we try all possible swaps in nums[begin:]
    static void backtrack(vector<int>& nums, int begin, vector<vector<int>>& res) {
        if (begin == nums.size()) {  // or equivalently begin == nums.size() - 1 because swap() has no effect
            res.push_back(nums);
            return;
        }
        int new_begin = begin + 1;
        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            backtrack(nums, new_begin, res);  // IMPORTANT: unlike subset/combination, new_begin is not i + 1
            // 2nd swap is optional, if we don't need to restore the original nums
            swap(nums[begin], nums[i]);
        }
    }
};
// @lc code=end

