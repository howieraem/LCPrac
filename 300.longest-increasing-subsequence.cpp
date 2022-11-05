/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Greedy + Binary Search
    // T: O(n * log(n))
    // S: O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;

        for (const auto& x : nums) {
            if (sub.empty() || sub.back() < x) {
                // If x is greater than all current number in sub, append it to the back of sub
                sub.push_back(x);
            } else {
                // If x <= sub.back(), find index of the number in sub that is no less than x,
                // and replace that number with x
                sub[left_bound(sub, x)] = x;
            }
        }

        // Note that `sub` at this point is not the actual longest subsequence, 
        // but sub.size() is the length of the longest subsequence
        return sub.size();
    }

    int left_bound(const vector<int>& nums, int target) {
        auto lb = std::lower_bound(nums.cbegin(), nums.cend(), target);
        return lb != nums.end() ? lb - nums.cbegin() : nums.size() - 1;
    }
};
// @lc code=end

