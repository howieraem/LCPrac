/*
 * @lc app=leetcode id=2195 lang=cpp
 *
 * [2195] Append K Integers With Minimal Sum
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    long long minimalKSum(vector<int>& nums, int k) {
        std::set<int> s(nums.begin(), nums.end());

        // Compute the minimal possible sum as k * (k + 1) / 2.
        // (equation of sum of arithmetic progression 1...k). 
        // Then, we go through unique numbers in the array, and 
        // substitute all numbers less than or equal to k with 
        // increasing numbers greater than k.
        long long ans = ((long long)k * (k + 1)) >> 1;
        for (const int& x : s) {
            if (x <= k) {
                ans += (++k) - x;
            }
        }
        return ans;
    }
};
// @lc code=end
