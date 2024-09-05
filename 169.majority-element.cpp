/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Boyer-Moore Majority Vote Algo
    // T: O(n)
    // S: O(1)
    int majorityElement(vector<int>& nums) {
        int cand = 0;
        int cnt = 0;
        for (const int& x : nums) {
            if (cnt == 0) {
                cand = x;
            }
            if (x == cand) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return cand;
    }
};
// @lc code=end

