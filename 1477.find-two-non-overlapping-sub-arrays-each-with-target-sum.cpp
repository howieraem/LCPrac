/*
 * @lc app=leetcode id=1477 lang=cpp
 *
 * [1477] Find Two Non-overlapping Sub-arrays Each With Target Sum
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int minSumOfLengths(vector<int>& arr, int target) {
        /** Belows also works for negative numbers in arr. */
        const int n = arr.size();
        int cur_sum = 0, min_len = n;  // upper bound of each min_len is n as 2 subarrays cannot overlap
        unordered_map<int, int> sum_idxs;

        // left[i] is the size of the shortest subarray in arr [0, i] that sums up to target
        vector<int> left(n);
        sum_idxs[0] = -1;  // IMPORTANT
        for (int i = 0; i < n; ++i) {
            cur_sum += arr[i];  // prefix sum
            auto it = sum_idxs.find(cur_sum - target);
            if (it != sum_idxs.end()) {
                min_len = std::min(min_len, i - it->second);
            }
            left[i] = min_len;
            sum_idxs[cur_sum] = i;
        }

        sum_idxs.clear();
        cur_sum = 0;
        min_len = n;

        // right[i] is the size of the shortest subarray in arr [i, n - 1] that sums up to target
        vector<int> right(n);
        sum_idxs[0] = n;  // IMPORTANT
        for (int i = n - 1; i >= 0; --i) {
            cur_sum += arr[i];  // suffix sum
            auto it = sum_idxs.find(cur_sum - target);
            if (it != sum_idxs.end()) {
                min_len = std::min(min_len, it->second - i);
            }
            right[i] = min_len;
            sum_idxs[cur_sum] = i;
        }

        // find the combo with smallest total length
        int ans = n + 1;    // upper bound of total length is n + 1
        for (int i = 1; i < n; ++i) {
            // IMPORTANT: no overlap, so index for left is i - 1
            if (left[i - 1] != n && right[i] != n) {
                ans = std::min(ans, left[i - 1] + right[i]);
            }
        }
        return ans < n + 1 ? ans : -1;
    }

    // Follow-up: find n subarrays instead of 2
    // https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/discuss/688689
};
// @lc code=end

