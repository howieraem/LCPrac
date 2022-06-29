/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;
using std::pair;

// @lc code=start
class Solution {
    int get_power(const int& val, unordered_map<int, int>& memo) {
        if (memo.find(val) != memo.end()) return memo[val];
        int steps = 0, cur = val;
        while (cur != 1) {
            if (cur & 1) {
                cur = cur * 3 + 1;
            } else {
                cur >>= 1;
            }
            ++steps;
        }
        memo[val] = steps;
        return steps;
    }

public:
    // T: O(n*log(n)), n := hi - lo
    // S: O(n)
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> vec;
        vec.reserve(hi - lo + 1);
        unordered_map<int, int> memo;
        for (int x = lo; x <= hi; ++x) {
            vec.push_back({get_power(x, memo), x});
        }
        std::sort(vec.begin(), vec.end());
        return vec[k - 1].second;
    }
};
// @lc code=end

