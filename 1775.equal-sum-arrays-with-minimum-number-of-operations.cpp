/*
 * @lc app=leetcode id=1775 lang=cpp
 *
 * [1775] Equal Sum Arrays With Minimum Number of Operations
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m + n)
    // S: O(s), s := 6 in this question
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() * 6 < nums2.size() || nums1.size() > nums2.size() * 6) {
            return -1;
        }
        int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);

        // Always make sum1 the smaller to simplify the problem
        if (sum1 > sum2) {
            std::swap(nums1, nums2);
            std::swap(sum1, sum2);
        }

        int cnt[6] {};
        for (const int& x : nums1) {
            ++cnt[6 - x];  // count the increases
        }
        for (const int& x : nums2) {
            ++cnt[x - 1];  // count the decreases
        }
        int i = 5, ans = 0;

        // Increase sum1 to reach sum2
        while (sum1 < sum2) {
            while (cnt[i] == 0) {
                --i;
            }
            sum1 += i;
            --cnt[i];
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

