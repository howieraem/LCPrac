/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * n!), n := len(nums)
    // S: O(len(nums)) for path copying and recursion
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());   // IMPORTANT: sort nums to help deduplicate
        // If i-th bit is 1, then nums[i] has not been visited
        // If n > 64, use a vector to mark visited instead
        int vis_mask = (1 << nums.size()) - 1;   
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, path, vis_mask, res);
        return res;
    }

private:
    static void backtrack(const vector<int>& nums, vector<int>& path, int& vis_mask, vector<vector<int>>& res) {
        if (!vis_mask) { // or path.size() == nums.size()
            res.push_back(vector<int>(path));
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!((vis_mask >> i) & 1)) continue;  // visited
            if (i > 0 && nums[i] == nums[i - 1] && ((vis_mask >> (i - 1)) & 1)) {
                // IMPORTANT: skip duplicates
                continue;
            }
            
            path.push_back(nums[i]);
            vis_mask &= ~(1 << i);

            backtrack(nums, path, vis_mask, res);
            
            path.pop_back();
            vis_mask |= (1 << i);
        }
    }
};
// @lc code=end

