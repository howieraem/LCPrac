/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
    static void backtrack(const vector<int> &nums, int begin, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(vector<int>(path));
        // Subset elements are unordered (thus combinations of different lengths).
        // Main difference between combination and permutation: 
        // - permutation starts from i = 0 and marks visited
        // - combination has a cutoff (no need to mark visited explicitly)
        for (int i = begin; i < nums.size(); ++i) {
            if (i > begin && nums[i] == nums[i - 1]) {
                // IMPORTANT: skip duplicates
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();
        }
    }

public:
    // T: O(n * 2 ^ n) worst case n := len(nums) if nums are unique, otherwise n := the number of unique nums
    // S: O(len(nums)) path copying
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort nums beforehand to filter duplicates more easily
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }
};
// @lc code=end

