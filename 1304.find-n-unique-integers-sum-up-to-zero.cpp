/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> sumZero(int n) {
        vector<int> res;
        res.reserve(n);

        // If n is odd, append a 0
        if (n & 1) {
            res.push_back(0);
            --n;
        }

        // Make the result symmetric, i.e. append 
        // one positive num and one negative num
        n >>= 1;
        for (int i = 1; i <= n; ++i) {
            res.push_back(i);
            res.push_back(-i);
        }
        return res;
    }
};
// @lc code=end

