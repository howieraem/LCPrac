/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */
#include <bits/stdc++.h>

using std::vector;
using std::unordered_set;

// @lc code=start
class Solution {
public:
    // Hash Set
    // T: O(n1 + n2)
    // S: O(min(n1, n2))
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }
        unordered_set<int> st(nums1.cbegin(), nums1.cend());
        
        vector<int> res;
        res.reserve(std::min(nums1.size(), nums2.size()));
        for (const int& x : nums2) {
            // set.erase(x) returns 1 if x is in set, 0 otherwise
            if (st.erase(x)) {
                res.push_back(x);
            }
        }
        return res;
    }
};
// @lc code=end

