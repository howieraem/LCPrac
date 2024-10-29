/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include <bits/stdc++.h>

using std::vector;
using std::max;

// @lc code=start
class Solution {
public:
    // Sorting + backtracking
    // T: O(n ^ l) worst case, n := len(candidates), l := target / min(candidates)
    // S: O(l)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());  // helps pruning
        vector<int> path;
        backtrack(path, candidates, target, res);
        return res;
    }

private:
    static void backtrack(vector<int> &path, const vector<int>& candidates, int remain, vector<vector<int>> &res) {
        if (remain == 0) {
            res.push_back(vector<int>(path));
            return;
        }
        // The same number may be chosen from candidates an unlimited number of times
        for (const int &num : candidates) {
            if (num > remain) {
                // prune
                break;
            }
            if (!path.empty() && num < path.back()) {
                // candidates sorted
                continue;
            }
            path.push_back(num);
            backtrack(path, candidates, remain - num, res);
            path.pop_back();
        }
    }
};
// @lc code=end

