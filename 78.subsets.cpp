/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    static void backtrack(const vector<int> &nums, int begin, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(vector<int>(path));
        for (int i = begin; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();
        }
    }

public:
    // Solution 1: backtracking
    // T: O(n * 2 ^ n)
    // S: O(n) path copying
    vector<vector<int>> subsets(vector<int>& nums) {
        // Because nums are unique, no need to sort nums beforehand
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums, 0, path, res);
        return res;
    }

    /*
    // Solution 2: bit set and indexing, works well if len(nums) is small
    // T: O(n * 2 ^ n)
    // S: O(n) largest subset is nums itself (might be considered O(1) because of std::move())
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> res;
        res.reserve(1 << n);
        vector<int> subset;
        int all_visited_mask = (1 << n) - 1;
        for (int mask = 0; mask <= all_visited_mask; ++mask) {
            // mask represents a case of the subset of indices
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    // Check if the ith bit of mask is set
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(std::move(subset));
            // subset.clear();
        }
        return res;
    }
    */
};
// @lc code=end

