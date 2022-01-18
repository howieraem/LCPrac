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
    // T: O(n^l) worst case, n := len(candidates), l := target / min(candidates)
    // S: O(l)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrack(path, candidates, target, res);
        return res;
    }

private:
    static void backtrack(vector<int> &path, vector<int>& candidates, int remain, vector<vector<int>> &res) {
        if (!remain) {
            res.push_back(vector<int>(path));
            return;
        }
        for (const int &num : candidates) {
            if (num > remain)  break;
            if (path.size() && num < path.back())  continue;
            path.push_back(num);
            backtrack(path, candidates, remain - num, res);
            path.pop_back();
        }
    }
};
// @lc code=end

