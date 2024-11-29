/*
 * @lc app=leetcode id=1865 lang=cpp
 *
 * [1865] Finding Pairs With a Certain Sum
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
// Hash map + arrays, variant of two sum
// S: O(m + n) if copies needed, O(n) otherwise
class FindSumPairs {
    vector<int> _nums1;
    vector<int> _nums2;
    unordered_map<int, int> nums2_freqs;

public:
    // T: O(n), or O(m * log(m) + n)
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // If no need to make copies
        _nums1.swap(nums1);
        _nums2.swap(nums2);

        for (const int& x : _nums2) {
            ++nums2_freqs[x];
        }

        // Optional: it might be useful to sort nums1 if nums2 contains positive numbers only and nums1 contains many numbers that are greater than tot
        std::sort(_nums1.begin(), _nums1.end());
    }
    
    // T: O(1)
    void add(int index, int val) {
        if (index >= _nums2.size()) {
            return;
        }
        --nums2_freqs[_nums2[index]];
        _nums2[index] += val;
        ++nums2_freqs[_nums2[index]];
    }
    
    // T: O(m)
    int count(int tot) {
        int ans = 0;
        for (const int& x : _nums1) {
            if (x > tot) {
                // Constraint: nums1 sorted ASC and nums2 must contain only non-negative numbers
                break;
            }
            ans += nums2_freqs[tot - x];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end

