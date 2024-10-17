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
    // T: O(n! / (k! * (n - k)!))
    // S: O(k) recursion?
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k <= 0 || n < k) {
            return res;
        }
        vector<int> track;
        backtrack(n, k, 1, track, res);
        return res;
    }

private:
    void backtrack(const int& n, const int& k, int start, vector<int>& track, vector<vector<int>>& res) {
        if (track.size() == k) {
            res.push_back(vector<int>(track));
            return;
        }
        
        // Main difference between combination and permutation: 
        // - permutation starts from i = 0 and marks visited
        // - combination has a cutoff (no need to mark visited explicitly)
        for (int i = start; i <= n; ++i) {
            track.push_back(i);
            backtrack(n, k, i + 1, track, res);
            track.pop_back();
        }
    }
};
// @lc code=end

