/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    /*
    // Solution 1: backtracking
    // T: O(n * 2^n)
    // S: O(n)
    static void backtrack(const vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(vector<int>(path));
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }
    */

public:
    // Solution 2: bit set and indexing
    // T: O(n * 2 ^ n)
    // S: O(1)
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> res;
        vector<int> subset;
        for (int i = 0; i < (1 << n); ++i) {
            // i represents a possibility of the subset of indices
            subset.clear();
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    // Check if the jth bit of i is set
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};
// @lc code=end

