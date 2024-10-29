/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // backtracking
    // T: O(n! / (k! * (n - k)!))
    // S: O(k) recursion?
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k <= 0 || n < k) {
            return res;
        }
        // vector<int> path;
        vector<int> path(k, -1);
        // backpath(n, k, 1, path, res);
        backpath(n, k, 1, path, res, 0);
        return res;
    }

private:
    void backpath(const int& n, const int& k, int start, vector<int>& path, vector<vector<int>>& res, int path_p) {
        // if (path.size() == k) {
        if (path_p == k) {
            res.push_back(vector<int>(path));
            return;
        }
        
        // Main difference between combination and permutation: 
        // - permutation starts from i = 0 and marks visited
        // - combination has a cutoff (no need to mark visited explicitly)
        for (int i = start; i <= n; ++i) {
            // path.push_back(i);
            // backpath(n, k, i + 1, path, res);
            // path.pop_back();
            path[path_p] = i;
            backpath(n, k, i + 1, path, res, path_p + 1);
            path[path_p] = -1;
        }
    }
};
// @lc code=end

