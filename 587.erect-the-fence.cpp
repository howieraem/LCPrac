/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
    static bool cmp(const vector<int> &p1, const vector<int> &p2) {
        return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
    }

    static long long cross(const vector<int> &o, const vector<int> &a, const vector<int> &b) {
        return (long long) (a[0] - o[0]) * (b[1] - o[1]) -
               (long long) (a[1] - o[1]) * (b[0] - o[0]);
    }

public:
    // T: O(n * log(n))
    // S: O(n)
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), cmp);  // sort points lexicographically
        const int n = trees.size();
        int p = 0;
        vector<vector<int>> res;

        // build lower hull
        for (int i = 0; i < n; ++i) {
            while (res.size() >= 2 && cross(res[res.size() - 2], res.back(), trees[i]) < 0) {
                res.pop_back();
            }
            res.push_back(trees[i]);
        }
        if (res.size() == n)  return res;

        // build upper hull
        for (int i = n - 2; i >= 0; --i) {
            while (res.size() >= 2 && cross(res[res.size() - 2], res.back(), trees[i]) < 0) {
                res.pop_back();
            }
            res.push_back(trees[i]);
        }

        res.pop_back();
        return res;
    }
};
// @lc code=end

